/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDGUSSERIAL_H
#define WTDGUSSERIAL_H

class DGUSSerial
{
public:
	DGUSSerial();

	static void Init(unsigned long baud);
	static int peek(void);
	static int read(void);
	static void flush(void);
	static uint8_t available(void);
	static void write(const uint8_t c);
	static void write(const uint8_t* buffer, unsigned int size);

	static void payload_reset();
	static void payload_send();
	static void payload_append_byte(uint8_t data);
	static void payload_append_int(uint16_t data);
	static void payload_append_float(float data);
	static void payload_append_buffer(uint8_t* buffer);
	static void payload_append_string(char* str);

	static void SendString(uint16_t addr, const char* str);
	static void SendString(uint16_t addr, const char* str, uint8_t total_length);
	static void SendString_P(uint16_t addr, const char* str);
	static void SendString_P(uint16_t addr, const char* str, uint8_t length);
	static void SendString(uint16_t addr, int data, int length);
	static void SendInt16(uint16_t addr, int data);
	static void SendFloat(uint16_t addr, float data);

	static void LoadScreen(uint8_t screenID);
	static void ResetScreen();

private:

};

extern DGUSSerial dserial;

#endif