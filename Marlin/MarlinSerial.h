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
 * MarlinSerial.h - Hardware serial library for Wiring
 * Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
 *
 * Modified 28 September 2010 by Mark Sproul
 * Modified 14 February 2016 by Andreas Hardtung (added tx buffer)
 * Modified 01 October 2017 by Eduardo José Tagle (added XON/XOFF)
 */

#ifndef _MARLINSERIAL_H_
#define _MARLINSERIAL_H_

#include "MarlinConfig.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2
#define BYTE 0

// Define constants and variables for buffering serial data.
// Use only 0 or powers of 2 greater than 1
// : [0, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, ...]
#ifndef RX_BUFFER_SIZE
  #define RX_BUFFER_SIZE 256
#endif
// 256 is the max TX buffer limit due to uint8_t head and tail.
#ifndef TX_BUFFER_SIZE
  #define TX_BUFFER_SIZE 32
#endif

#if USE_MARLINSERIAL

  #if RX_BUFFER_SIZE > 256
    typedef uint16_t ring_buffer_pos_t;
  #else
    typedef uint8_t ring_buffer_pos_t;
  #endif

  #if ENABLED(SERIAL_STATS_DROPPED_RX)
    extern uint8_t rx_dropped_bytes;
  #endif

  #if ENABLED(SERIAL_STATS_RX_BUFFER_OVERRUNS)
    extern uint8_t rx_buffer_overruns;
  #endif

  #if ENABLED(SERIAL_STATS_RX_FRAMING_ERRORS)
    extern uint8_t rx_framing_errors;
  #endif

  #if ENABLED(SERIAL_STATS_MAX_RX_QUEUED)
    extern ring_buffer_pos_t rx_max_enqueued;
  #endif

  class MarlinSerial 
  {

    public:
      MarlinSerial() {};
      static void begin(const long host_baud, const long host_wifi);
      static void end();
      static int peek0(void);
	  static int peek1(void);
      static int read0(void);
	  static int read1(void);
      static void flush(void);
      static ring_buffer_pos_t available0(void);
	  static ring_buffer_pos_t available1(void);
      static void write0(const uint8_t c);
	  static void write1(const uint8_t c);
      static void flushTX0(void);
	  static void flushTX1(void);

	  FORCE_INLINE static void write(const char* str) { while (*str) { write0(*str); write1(*str++); }; }
	  FORCE_INLINE static void write(const uint8_t* buffer, size_t size) { while (size--) { write0(*buffer); write1(*buffer++); }; }
	  FORCE_INLINE static void print(const String& s) { for (int i = 0; i < (int)s.length(); i++) { write0(s[i]); write1(s[i]); }; }
      FORCE_INLINE static void print(const char* str) { write(str); }

      static void print(char, int = BYTE);
      static void print(unsigned char, int = BYTE);
      static void print(int, int = DEC);
      static void print(unsigned int, int = DEC);
      static void print(long, int = DEC);
      static void print(unsigned long, int = DEC);
      static void print(double, int = 2);

      static void println(const String& s);
      static void println(const char[]);
      static void println(char, int = BYTE);
      static void println(unsigned char, int = BYTE);
      static void println(int, int = DEC);
      static void println(unsigned int, int = DEC);
      static void println(long, int = DEC);
      static void println(unsigned long, int = DEC);
      static void println(double, int = 2);
      static void println(void);
      operator bool() { return true; }

    private:
      static void printNumber(unsigned long, const uint8_t);
      static void printFloat(double, uint8_t);
  };

  extern MarlinSerial customizedSerial;

#endif // USE_MARLINSERIAL

#endif // _MARLINSERIAL_H_
