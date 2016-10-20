
#include "port.h"


Port::Port(int16_t portnumber){
	this->portnumber = portnumber;
}
Port::~Port(){
}


Port8Bit::Port8Bit(int16_t portnumber)
: Port(portnumber){
}
Port8Bit::~Port8Bit(){
}
void Port8Bit::Write(uint8_t data){
	
	__asm__volatile("outb %0, %1" : : "a" (data), "Nd" (portnumber));
	
}
uint8_t Port8Bit::Read(){
	
	__asm__volatile("outb %1, %0" : : "=a" (result), "Nd" (portnumber));
}

Port16Bit::Port16Bit(int16_t portnumber)
: Port(portnumber){
}
Port16Bit::~Port16Bit(){
}
void Port16Bit::Write(uint16_t data){
	
	__asm__volatile("outb %0, %1" : : "a" (data), "Nd" (portnumber));
	
}
uint16_t Port16Bit::Read(){
	
	__asm__volatile("outb %1, %0" : : "=a" (result), "Nd" (portnumber));
}

Port32Bit::Port32Bit(int16_t portnumber)
: Port(portnumber){
}
Port32Bit::~Port32Bit(){
}
void Port32Bit::Write(uint32_t data){
	
	__asm__volatile("outb %0, %1" : : "a" (data), "Nd" (portnumber));
	
}
uint32_t Port32Bit::Read(){
	
	__asm__volatile("outb %1, %0" : : "=a" (result), "Nd" (portnumber));
}
