
#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H
#include "types.h"
#define IDT_SIZE 256

struct IDT_entry{
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
};





void idt_init();
extern "C" void keyboard_handler_main();
void kb_init();

extern void load_idt(void* idt_ptr)  __asm__("load_idt");
extern void keyboard_handler()  __asm__("keyboard_handler");

extern "C" int8_t read_port(int16_t address);
extern "C" void write_port(int16_t address, int8_t data);
#endif
