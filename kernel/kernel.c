#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "gdt.h"
#include "idt.h"
#include "keyboard.h"
#include "terminal.h"
#include "stdfunc.h"
#include "common.h"
#include "timer.h"
#include "shell.h"

#if defined(__linux__)
#error "Nie skompilowano cross-compiler'em."
#endif

#if !defined(__i386__)
#error "Kernel musi byc skompilowany cross-compiler'em."
#endif

//Entry point for kernel
void kernel_main() 
{
	terminal_initialize();
	terminal_writestring("HELLO WORLD!\n");

	terminal_writestring("[+]Initialization of GDT\n");
    InitializeGDT();

	terminal_writestring("[+]Initialization of IDT\n");
	InitializeIDT();

    terminal_writestring("[+]Initialization of Timer at a frequency of 50Hz\n");
    InitializeTimer(50);

	terminal_writestring("[+]Initialization of Keyboard\n");
	InitializeKeyboard();

    terminal_writestring(itoa('0', 10));

    terminal_writestring("[+]Initialization of Shell\n");
    InitializeShell();

}
