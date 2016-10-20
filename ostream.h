#ifndef __OSTREAM_H
#define __OSTREAM_H
#include "types.h"

#define WIDTH 80
#define HEIGHT 25


class ostream{
public:
	ostream();
	~ostream();
	friend ostream& operator<<(ostream& s,const char* str);
	friend ostream& operator<<(ostream& s,const int i);
	friend ostream& operator<<(ostream& s,const char c);
	friend ostream& operator<<(ostream& s,const float f);
	
private:
	void scroll_down();
	int x,y;
	volatile uint16_t* VGA_buffer;
	uint8_t color;
};
#endif
