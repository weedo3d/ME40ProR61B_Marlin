/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"

#define LCD_RX_BUFFER_SIZE 64
#define LCD_TX_BUFFER_SIZE 64

#define DGUS_PAYLOAD_LENGTH	64


#define sw_barrier2() asm volatile("": : :"memory");

struct lcd_ring_buffer_r {
	uint8_t buffer[LCD_RX_BUFFER_SIZE];
	volatile uint8_t head, tail, count;
};

lcd_ring_buffer_r rx_buffer3 = { { 0 }, 0, 0 , 0};
static bool _written3;

uint8_t dgus_payload[DGUS_PAYLOAD_LENGTH];
uint8_t dgus_outbuffer[DGUS_PAYLOAD_LENGTH + 3];
uint8_t dpayload_length = 0;


void DGUSSerial::payload_reset()
{
	dpayload_length = 0;
	memset((char *)dgus_payload, 0, DGUS_PAYLOAD_LENGTH);
}

void DGUSSerial::payload_send()
{
	dgus_outbuffer[0] = DGUS_START_BYTE_1;
	dgus_outbuffer[1] = DGUS_START_BYTE_2;
	dgus_outbuffer[2] = dpayload_length;
	for (uint8_t i = 0; i < dpayload_length; i++)
		dgus_outbuffer[i + 3] = dgus_payload[i];
	write(dgus_outbuffer, dpayload_length + 3);
}

void DGUSSerial::payload_append_byte(uint8_t data)
{
	if (dpayload_length < DGUS_PAYLOAD_LENGTH)
	{
		dgus_payload[dpayload_length] = data;
		dpayload_length++;
	}
}

void DGUSSerial::payload_append_int(uint16_t data)
{
	if (dpayload_length < DGUS_PAYLOAD_LENGTH - 1)
	{
		dgus_payload[dpayload_length] = data >> 8;
		dgus_payload[dpayload_length + 1] = data & 0xFF;
		dpayload_length += 2;
	}
}

void DGUSSerial::payload_append_float(float data)
{
	if (dpayload_length < DGUS_PAYLOAD_LENGTH - 1)
	{
		uint8_t a[4], i;

		uint8_t *pdata = (uint8_t*)(&data);
		for (i = 0; i < 4; i++)
			a[i] = *pdata++;

		payload_append_byte(a[3]);
		payload_append_byte(a[2]);
		payload_append_byte(a[1]);
		payload_append_byte(a[0]);
	}
}

void DGUSSerial::payload_append_buffer(uint8_t* buffer)
{
	uint8_t* p = buffer;

	while (*p != 0 && dpayload_length < DGUS_PAYLOAD_LENGTH)
	{
		dgus_payload[dpayload_length] = *p;
		dpayload_length++;
		p++;
	}
}

void DGUSSerial::payload_append_string(char* str)
{
	payload_append_buffer((uint8_t*) str);
}

void DGUSSerial::SendString(uint16_t addr, const char* str)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	payload_append_string((char*)str);
	payload_send();
}

void DGUSSerial::SendString(uint16_t addr, const char* str, uint8_t total_length)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	uint8_t count = 0;
	while (byte ch = *str++)
	{
		payload_append_byte(ch);
		count++;
	}
	while (count < total_length)
	{
		payload_append_byte(0x20);
		count++;
	}
	payload_send();
}

void DGUSSerial::SendString_P(uint16_t addr, const char* str)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	while (byte ch = pgm_read_byte(str++)) payload_append_byte(ch);
	payload_send();
}

void DGUSSerial::SendString_P(uint16_t addr, const char* str, uint8_t total_length)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(addr);
	uint8_t count = 0;
	while (byte ch = pgm_read_byte(str++))
	{
		payload_append_byte(ch);
		count++;
	}
	while (count < total_length)
	{
		payload_append_byte(0x20);
		count ++;
	}
	payload_send();
}

void DGUSSerial::SendString(uint16_t addr, int data, int length)
{
	char b[6];
	ZERO(b);
	if (length == 5)
	{
		sprintf_P(b, PSTR("%5d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[5] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else if (length == 4)
	{
		sprintf_P(b, PSTR("%4d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[4] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else if (length == 3)
	{
		memset(b, 0x20, 4);
		sprintf_P(b, PSTR("%3d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[3] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else if (length == 2)
	{
		sprintf_P(b, PSTR("%2d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[2] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	else
	{
		sprintf_P(b, PSTR("%1d"), data);
		payload_reset();
		payload_append_byte(DGUS_CMD_WriteVAR);
		payload_append_int(addr);
		b[1] = 0;
		payload_append_string(b);
		dserial.payload_send();
	}
	
}

void DGUSSerial::SendInt16(uint16_t addr, int data)
{
	dserial.payload_reset();
	dserial.payload_append_byte(DGUS_CMD_WriteVAR);
	dserial.payload_append_int(addr);
	dserial.payload_append_int(data);
	dserial.payload_send();
}

void DGUSSerial::SendFloat(uint16_t addr, float data)
{
	dserial.payload_reset();
	dserial.payload_append_byte(DGUS_CMD_WriteVAR);
	dserial.payload_append_int(addr);
	dserial.payload_append_float(data);
	dserial.payload_send();
}

DGUSSerial::DGUSSerial()
{

}

void DGUSSerial::Init(unsigned long baud)
{
	uint16_t baud_setting;

	UCSR3A = _BV(U2X3);
	baud_setting = (F_CPU / 4 / baud - 1) / 2;

	UBRR3H = baud_setting >> 8;
	UBRR3L = baud_setting;

	SBI(UCSR3B, RXEN3);
	SBI(UCSR3B, TXEN3);
	SBI(UCSR3B, RXCIE3);

	_written3 = false;

	rx_buffer3 = { { 0 }, 0, 0 , 0 };
}


FORCE_INLINE uint8_t atomic_read_rx_head3()
{
	return rx_buffer3.head;
}

FORCE_INLINE uint8_t atomic_read_rx_tail3()
{
	return rx_buffer3.tail;
}

FORCE_INLINE void atomic_set_rx_tail3(uint8_t value)
{
	rx_buffer3.tail = value;
}

FORCE_INLINE void store_rxd_char3()
{
	const uint8_t t = atomic_read_rx_tail3();

	uint8_t h = rx_buffer3.head;

	uint8_t i = h + 1;
	if (i >= LCD_RX_BUFFER_SIZE)
		i = 0;

	uint8_t c = UDR3;

	if (i != t) 
	{
		rx_buffer3.buffer[h] = c;
		h = i;
		rx_buffer3.count++;
	}

	rx_buffer3.head = h;
}


ISR(USART3_RX_vect) { store_rxd_char3(); }

void DGUSSerial::flush(void)
{
	atomic_set_rx_tail3(atomic_read_rx_head3());
}

void DGUSSerial::write(const uint8_t c)
{
	_written3 = true;
	while (!TEST(UCSR3A, UDRE3)) sw_barrier2();
	UDR3 = c;
}

void DGUSSerial::write(const uint8_t* buffer, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		write(buffer[i]);
}

int DGUSSerial::read()
{
	const uint8_t h = atomic_read_rx_head3();

	uint8_t t = rx_buffer3.tail;

	if (h == t) return -1;

	const int v = rx_buffer3.buffer[t];
	t++;
	rx_buffer3.count--;

	if (t >= LCD_RX_BUFFER_SIZE)
		t = 0;

	atomic_set_rx_tail3(t);

	return v;
}

uint8_t DGUSSerial::available()
{
	return rx_buffer3.count;
}

int DGUSSerial::peek(void)
{
	const uint8_t h = atomic_read_rx_head3(), t = rx_buffer3.tail;
	return h == t ? -1 : rx_buffer3.buffer[t];
}

void DGUSSerial::LoadScreen(uint8_t screenID)
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(DGUS_SYS_PIC_Set);
	payload_append_byte(0x5A);
	payload_append_byte(0x01);
	payload_append_byte(0x00);
	payload_append_byte(screenID);
	payload_send();
}

void DGUSSerial::ResetScreen()
{
	payload_reset();
	payload_append_byte(DGUS_CMD_WriteVAR);
	payload_append_int(DGUS_SYS_System_Reset);
	payload_append_byte(0x55);
	payload_append_byte(0xAA);
	payload_append_byte(0x5A);
	payload_append_byte(0xA5);
	payload_send();
}