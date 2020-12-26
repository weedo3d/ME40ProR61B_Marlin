/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * MarlinSerial.cpp - Hardware serial library for Wiring
 * Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
 *
 * Modified 23 November 2006 by David A. Mellis
 * Modified 28 September 2010 by Mark Sproul
 * Modified 14 February 2016 by Andreas Hardtung (added tx buffer)
 * Modified 01 October 2017 by Eduardo José Tagle (added XON/XOFF)
 * Modified 10 June 2018 by Eduardo José Tagle (See #10991)
 */

// Disable HardwareSerial.cpp to support chips without a UART (Attiny, etc.)

#include "MarlinConfig.h"

#if USE_MARLINSERIAL && (defined(UBRRH) || defined(UBRR0H) || defined(UBRR1H) || defined(UBRR2H) || defined(UBRR3H))

#include "MarlinSerial.h"
#include "Marlin.h"

struct ring_buffer_r
{
  unsigned char buffer[RX_BUFFER_SIZE];
  volatile ring_buffer_pos_t head, tail;
};

// for uart0
ring_buffer_r rx_buffer0 = {{0}, 0, 0};
static bool _written0;

// for uart1
ring_buffer_r rx_buffer1 = {{0}, 0, 0};
static bool _written1;

// A SW memory barrier, to ensure GCC does not overoptimize loops
#define sw_barrier() asm volatile("" \
                                  :  \
                                  :  \
                                  : "memory");

#if ENABLED(EMERGENCY_PARSER)
#include "emergency_parser.h"
#endif

// "Atomically" read the RX head index value without disabling interrupts:
// This MUST be called with RX interrupts enabled, and CAN'T be called
// from the RX ISR itself!
FORCE_INLINE ring_buffer_pos_t atomic_read_rx_head0()
{
  // With an 8bit index, reads are always atomic. No need for special handling
  return rx_buffer0.head;
}

FORCE_INLINE ring_buffer_pos_t atomic_read_rx_head1()
{
  // With an 8bit index, reads are always atomic. No need for special handling
  return rx_buffer1.head;
}

// Set RX tail index, taking into account the RX ISR could interrupt
//  the write to this variable in the middle - So a backup strategy
//  is used to ensure reads of the correct values.
//    -Must NOT be called from the RX ISR -
FORCE_INLINE void atomic_set_rx_tail0(ring_buffer_pos_t value)
{
  rx_buffer0.tail = value;
}

FORCE_INLINE void atomic_set_rx_tail1(ring_buffer_pos_t value)
{
  rx_buffer1.tail = value;
}

// Get the RX tail index, taking into account the read could be
//  interrupting in the middle of the update of that index value
//    -Called from the RX ISR -
FORCE_INLINE ring_buffer_pos_t atomic_read_rx_tail0()
{
  // The true index is stable, return it
  return rx_buffer0.tail;
}

FORCE_INLINE ring_buffer_pos_t atomic_read_rx_tail1()
{
  // The true index is stable, return it
  return rx_buffer1.tail;
}

FORCE_INLINE void store_rxd_char0()
{
  // Get the tail - Nothing can alter its value while this ISR is executing, but there's
  // a chance that this ISR interrupted the main process while it was updating the index.
  // The backup mechanism ensures the correct value is always returned.
  const ring_buffer_pos_t t = atomic_read_rx_tail0();

  // Get the head pointer - This ISR is the only one that modifies its value, so it's safe to read here
  ring_buffer_pos_t h = rx_buffer0.head;

  // Get the next element
  ring_buffer_pos_t i = (ring_buffer_pos_t)(h + 1) & (ring_buffer_pos_t)(RX_BUFFER_SIZE - 1);

  // Read the character from the USART
  uint8_t c = UDR0;

  // If the character is to be stored at the index just before the tail
  // (such that the head would advance to the current tail), the RX FIFO is
  // full, so don't write the character or advance the head.
  if (i != t)
  {
    rx_buffer0.buffer[h] = c;
    h = i;
  }

  // Store the new head value - The main loop will retry until the value is stable
  rx_buffer0.head = h;
}

FORCE_INLINE void store_rxd_char1()
{
  // Get the tail - Nothing can alter its value while this ISR is executing, but there's
  // a chance that this ISR interrupted the main process while it was updating the index.
  // The backup mechanism ensures the correct value is always returned.
  const ring_buffer_pos_t t = atomic_read_rx_tail1();

  // Get the head pointer - This ISR is the only one that modifies its value, so it's safe to read here
  ring_buffer_pos_t h = rx_buffer1.head;

  // Get the next element
  ring_buffer_pos_t i = (ring_buffer_pos_t)(h + 1) & (ring_buffer_pos_t)(RX_BUFFER_SIZE - 1);

  // Read the character from the USART
  uint8_t c = UDR1;

  // If the character is to be stored at the index just before the tail
  // (such that the head would advance to the current tail), the RX FIFO is
  // full, so don't write the character or advance the head.
  if (i != t)
  {
    rx_buffer1.buffer[h] = c;
    h = i;
  }

  // Store the new head value - The main loop will retry until the value is stable
  rx_buffer1.head = h;
}

ISR(USART0_RX_vect) { store_rxd_char0(); }

ISR(USART1_RX_vect) { store_rxd_char1(); }

// Public Methods

void MarlinSerial::begin(const long baud1, const long baud3)
{
  uint16_t baud_setting1, baud_setting3;
  bool useU2X = true;

  if (useU2X)
  {
    UCSR0A = _BV(U2X0);
    UCSR1A = _BV(U2X1);
    baud_setting1 = (F_CPU / 4 / baud1 - 1) / 2;
    baud_setting3 = (F_CPU / 4 / baud3 - 1) / 2;
  }
  else
  {
    UCSR0A = 0;
    UCSR1A = 0;
    baud_setting1 = (F_CPU / 8 / baud1 - 1) / 2;
    baud_setting3 = (F_CPU / 8 / baud3 - 1) / 2;
  }

  // assign the baud_setting, a.k.a. ubbr (USART Baud Rate Register)
  UBRR0H = baud_setting1 >> 8;
  UBRR0L = baud_setting1;

  UBRR1H = baud_setting3 >> 8;
  UBRR1L = baud_setting3;

  SBI(UCSR0B, RXEN0);
  SBI(UCSR0B, TXEN0);
  SBI(UCSR0B, RXCIE0);

  SBI(UCSR1B, RXEN1);
  SBI(UCSR1B, TXEN1);
  SBI(UCSR1B, RXCIE1);

  _written0 = false;
  _written1 = false;
}

void MarlinSerial::end()
{
  CBI(UCSR0B, RXEN0);
  CBI(UCSR0B, TXEN0);
  CBI(UCSR0B, RXCIE0);
  CBI(UCSR0B, UDRIE0);

  CBI(UCSR1B, RXEN1);
  CBI(UCSR1B, TXEN1);
  CBI(UCSR1B, RXCIE1);
  CBI(UCSR1B, UDRIE1);
}

int MarlinSerial::peek0(void)
{
  const ring_buffer_pos_t h = atomic_read_rx_head0(), t = rx_buffer0.tail;
  return h == t ? -1 : rx_buffer0.buffer[t];
}

int MarlinSerial::peek1(void)
{
  const ring_buffer_pos_t h = atomic_read_rx_head1(), t = rx_buffer1.tail;
  return h == t ? -1 : rx_buffer1.buffer[t];
}

int MarlinSerial::read0(void)
{
  const ring_buffer_pos_t h = atomic_read_rx_head0();

  // Read the tail. Main thread owns it, so it is safe to directly read it
  ring_buffer_pos_t t = rx_buffer0.tail;

  // If nothing to read, return now
  if (h == t)
    return -1;

  // Get the next char
  const int v = rx_buffer0.buffer[t];
  t = (ring_buffer_pos_t)(t + 1) & (RX_BUFFER_SIZE - 1);

  // Advance tail - Making sure the RX ISR will always get an stable value, even
  // if it interrupts the writing of the value of that variable in the middle.
  atomic_set_rx_tail0(t);

  return v;
}

int MarlinSerial::read1(void)
{
  const ring_buffer_pos_t h = atomic_read_rx_head1();

  // Read the tail. Main thread owns it, so it is safe to directly read it
  ring_buffer_pos_t t = rx_buffer1.tail;

  // If nothing to read, return now
  if (h == t)
    return -1;

  // Get the next char
  const int v = rx_buffer1.buffer[t];
  t = (ring_buffer_pos_t)(t + 1) & (RX_BUFFER_SIZE - 1);

  // Advance tail - Making sure the RX ISR will always get an stable value, even
  // if it interrupts the writing of the value of that variable in the middle.
  atomic_set_rx_tail1(t);

  return v;
}

ring_buffer_pos_t MarlinSerial::available0(void)
{
  const ring_buffer_pos_t h = atomic_read_rx_head0(), t = rx_buffer0.tail;
  return (ring_buffer_pos_t)(RX_BUFFER_SIZE + h - t) & (RX_BUFFER_SIZE - 1);
}

ring_buffer_pos_t MarlinSerial::available1(void)
{
  const ring_buffer_pos_t h = atomic_read_rx_head1(), t = rx_buffer1.tail;
  return (ring_buffer_pos_t)(RX_BUFFER_SIZE + h - t) & (RX_BUFFER_SIZE - 1);
}

void MarlinSerial::flush(void)
{

  // Set the tail to the head:
  //  - Read the RX head index in a safe way. (See atomic_read_rx_head.)
  //  - Set the tail, making sure the RX ISR will always get a stable value, even
  //    if it interrupts the writing of the value of that variable in the middle.
  atomic_set_rx_tail0(atomic_read_rx_head0());
  atomic_set_rx_tail1(atomic_read_rx_head1());
}

void MarlinSerial::write0(const uint8_t c)
{
  _written0 = true;
  while (!TEST(UCSR0A, UDRE0))
    sw_barrier();
  UDR0 = c;
}

void MarlinSerial::write1(const uint8_t c)
{
  _written1 = true;
  while (!TEST(UCSR1A, UDRE1))
    sw_barrier();
  UDR1 = c;
}

void MarlinSerial::flushTX0(void)
{
  // No bytes written, no need to flush. This special case is needed since there's
  // no way to force the TXC (transmit complete) bit to 1 during initialization.
  if (!_written0)
    return;

  // Wait until everything was transmitted
  while (!TEST(UCSR0A, TXC0))
    sw_barrier();

  // At this point nothing is queued anymore (DRIE is disabled) and
  // the hardware finished transmission (TXC is set).
}

void MarlinSerial::flushTX1(void)
{
  // No bytes written, no need to flush. This special case is needed since there's
  // no way to force the TXC (transmit complete) bit to 1 during initialization.
  if (!_written1)
    return;

  // Wait until everything was transmitted
  while (!TEST(UCSR1A, TXC1))
    sw_barrier();

  // At this point nothing is queued anymore (DRIE is disabled) and
  // the hardware finished transmission (TXC is set).
}
//#endif // TX_BUFFER_SIZE == 0

/**
   * Imports from print.h
   */

void MarlinSerial::print(char c, int base)
{
  print((long)c, base);
}

void MarlinSerial::print(unsigned char b, int base)
{
  print((unsigned long)b, base);
}

void MarlinSerial::print(int n, int base)
{
  print((long)n, base);
}

void MarlinSerial::print(unsigned int n, int base)
{
  print((unsigned long)n, base);
}

void MarlinSerial::print(long n, int base)
{
  if (base == 0)
  {
    write0(n);
    write1(n);
  }
  else if (base == 10)
  {
    if (n < 0)
    {
      print('-');
      n = -n;
    }
    printNumber(n, 10);
  }
  else
    printNumber(n, base);
}

void MarlinSerial::print(unsigned long n, int base)
{
  if (base == 0)
  {
    write0(n);
    write1(n);
  }
  else
  {
    printNumber(n, base);
  }
}

void MarlinSerial::print(double n, int digits)
{
  printFloat(n, digits);
}

void MarlinSerial::println(void)
{
  print('\r');
  print('\n');
}

void MarlinSerial::println(const String &s)
{
  print(s);
  println();
}

void MarlinSerial::println(const char c[])
{
  print(c);
  println();
}

void MarlinSerial::println(char c, int base)
{
  print(c, base);
  println();
}

void MarlinSerial::println(unsigned char b, int base)
{
  print(b, base);
  println();
}

void MarlinSerial::println(int n, int base)
{
  print(n, base);
  println();
}

void MarlinSerial::println(unsigned int n, int base)
{
  print(n, base);
  println();
}

void MarlinSerial::println(long n, int base)
{
  print(n, base);
  println();
}

void MarlinSerial::println(unsigned long n, int base)
{
  print(n, base);
  println();
}

void MarlinSerial::println(double n, int digits)
{
  print(n, digits);
  println();
}

// Private Methods

void MarlinSerial::printNumber(unsigned long n, uint8_t base)
{
  if (n)
  {
    unsigned char buf[8 * sizeof(long)]; // Enough space for base 2
    int8_t i = 0;
    while (n)
    {
      buf[i++] = n % base;
      n /= base;
    }
    while (i--)
      print((char)(buf[i] + (buf[i] < 10 ? '0' : 'A' - 10)));
  }
  else
    print('0');
}

void MarlinSerial::printFloat(double number, uint8_t digits)
{
  // Handle negative numbers
  if (number < 0.0)
  {
    print('-');
    number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (uint8_t i = 0; i < digits; ++i)
    rounding *= 0.1;

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  print(int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits)
  {
    print('.');
    // Extract digits from the remainder one at a time
    while (digits--)
    {
      remainder *= 10.0;
      int toPrint = int(remainder);
      print(toPrint);
      remainder -= toPrint;
    }
  }
}

// Preinstantiate
MarlinSerial customizedSerial;

#endif // USE_MARLINSERIAL && (UBRRH || UBRR0H || UBRR1H || UBRR2H || UBRR3H)

// For AT90USB targets use the UART for BT interfacing
#if !USE_MARLINSERIAL && ENABLED(BLUETOOTH)
HardwareSerial bluetoothSerial;
#endif
