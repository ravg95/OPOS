#include "types.h"
#include "ostream.h"
#include "interrupts.h"

ostream out;
void printHelloMessage(){
out = ostream();
out<<"      ___           ___         ___           ___      \n";
out<<"     /\\  \\         /\\  \\       /\\  \\         /\\__\\     \n";
out<<"    /::\\  \\       /::\\  \\     /::\\  \\       /:/ _/_   \n";
out<<"   /:/\\:\\  \\     /:/\\:\\__\\   /:/\\:\\  \\     /:/ /\\  \\   \n";
out<<"  /:/  \\:\\  \\   /:/ /:/  /  /:/  \\:\\  \\   /:/ /::\\  \\  \n";
out<<" /:/__/ \\:\\__\\ /:/_/:/  /  /:/__/ \\:\\__\\ /:/_/:/\\:\\__\\ \n";
out<<" \\:\\  \\ /:/  / \\:\\/:/  /   \\:\\  \\ /:/  / \\:\\/:/ /:/  / \n";
out<<"  \\:\\  /:/  /   \\::/__/     \\:\\  /:/  /   \\::/ /:/  /  \n";
out<<"   \\:\\/:/  /     \\:\\  \\      \\:\\/:/  /     \\/_/:/  /   \n";
out<<"    \\::/  /       \\:\\__\\      \\::/  /        /:/  /    \n";
out<<"     \\/__/         \\/__/       \\/__/         \\/__/     \n";
out<<"\n";
out<<"  ____                      __       __      _           __            \n";
out<<" / __ \\_  _____ _____    __/ /  ___ / /_ _  (_)__  ___ _/ /_ __        \n";
out<<"/ /_/ / |/ / -_) __/ |/|/ / _ \\/ -_) /  ' \\/ / _ \\/ _ `/ / // /        \n";
out<<"\\____/|___/\\__/_/  |__,__/_//_/\\__/_/_/_/_/_/_//_/\\_, /_/\\_, /         \n";
out<<"  / _ \\___  ___  ____                            /___/  /___/          \n";
out<<" / ___/ _ \\/ _ \\/ __/                                                  \n";
out<<"/_/___\\___/\\___/_/        __  _             ____         __            \n";
out<<" / __ \\___  ___ _______ _/ /_(_)__  ___ _  / __/_ _____ / /____ __ _   \n";
out<<"/ /_/ / _ \\/ -_) __/ _ `/ __/ / _ \\/ _ `/ _\\ \\/ // (_-</ __/ -_)  ' \\_ \n";
out<<"\\____/ .__/\\__/_/  \\_,_/\\__/_/_//_/\\_, / /___/\\_, /___/\\__/\\__/_/_/_(_)\n";
out<<"    /_/                           /___/      /___/                     \n";
out<<"\n";
}
/*
typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
	for(constructor * i = &start_ctors; i != &end_ctors; i++){
		(*i)();
	}
}
*/

struct IDT_entry IDT[IDT_SIZE];

void idt_init(void)
{
	uint32_t keyboard_address;
	uint32_t idt_address;
	uint32_t idt_ptr[2];

	/* populate IDT entry of keyboard's interrupt */
	keyboard_address = (uint32_t) keyboard_handler; 
	IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
	IDT[0x21].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x21].zero = 0;
	IDT[0x21].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;
	

	/*     Ports
	*	 PIC1	PIC2
	*Command 0x20	0xA0
	*Data	 0x21	0xA1
	*/

	/* ICW1 - begin initialization */
	write_port(0x20 , 0x11);
	write_port(0xA0 , 0x11);

	/* ICW2 - remap offset address of IDT */
	/*
	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	*/
	write_port(0x21 , 0x20);
	write_port(0xA1 , 0x28);

	/* ICW3 - setup cascading */
	write_port(0x21 , 0x00);  
	write_port(0xA1 , 0x00);  

	/* ICW4 - environment info */
	write_port(0x21 , 0x01);
	write_port(0xA1 , 0x01);
	/* Initialization finished */

	/* mask interrupts */
	write_port(0x21 , 0xff);
	write_port(0xA1 , 0xff);

	/* fill the IDT descriptor */
	idt_address = (uint32_t)IDT ;
	idt_ptr[0] = (sizeof (struct IDT_entry) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16 ;

	load_idt(idt_ptr);
}
void kb_init(void)
{
	/* 0xFD is 11111101 - enables only IRQ1 (keyboard)*/
	write_port(0x21 , 0xFD);
	write_port(0xA1 , 0xFD);
}


extern "C" void kmain(const void* multiboot_struct, uint32_t magic_num) {
	

	printHelloMessage();
	idt_init();
	kb_init();
	while (1){
	};
}
