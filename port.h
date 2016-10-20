

#ifndef __PORT_H
#define __PORT_H
#include "stdint.h"


class Port {
protected:
	int16_t portnumber;
	Port(int16_t portnumber);
	~Port():
	
};

class Port8Bit : public Port {
public:
	int16_t portnumber;
	Port8Bit(int16_t portnumber);
	~Port8Bit():
	virtual void Write(uint8_t data);
	virtual uint8_t Read();
};

class Port8BitSlow : public Port8Bit {
public:
	int16_t portnumber;
	Port8BitSlow(int16_t portnumber);
	virtual void Write(uint8_t data);
	~Port8BitSlow():
};

class Port16Bit : public Port {
public:
	int16_t portnumber;
	Port16Bit(int16_t portnumber);
	~Port16Bit():
	virtual void Write(uint16_t data);
	virtual uint16_t Read();
};

class Port32Bit : public Port {
public:
	int16_t portnumber;
	Port32Bit(int16_t portnumber);
	~Port32Bit():
	virtual void Write(uint32_t data);
	virtual uint32_t Read();
};


#endif
