#ifndef __GDT_H
#define __GDT_H

#include <stdint.h>

	void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
	void gdt_install();
    void gdt_flush();


#endif
