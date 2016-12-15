#include "stddef.h"
#include "stdint.h"
#include "ostream.h"

extern "C" {
	#include "gdt.h"
}

void delay(int countdown_limit) {
	volatile int w = 0;
	while (w<countdown_limit) {
		w++;
	}
}
void printHelloMessage(){
ostream osout = ostream();

osout<<"      ___           ___         ___           ___      \n";
osout<<"     /\\  \\         /\\  \\       /\\  \\         /\\__\\     \n";
osout<<"    /::\\  \\       /::\\  \\     /::\\  \\       /:/ _/_   \n";
osout<<"   /:/\\:\\  \\     /:/\\:\\__\\   /:/\\:\\  \\     /:/ /\\  \\   \n";
osout<<"  /:/  \\:\\  \\   /:/ /:/  /  /:/  \\:\\  \\   /:/ /::\\  \\  \n";
osout<<" /:/__/ \\:\\__\\ /:/_/:/  /  /:/__/ \\:\\__\\ /:/_/:/\\:\\__\\ \n";
osout<<" \\:\\  \\ /:/  / \\:\\/:/  /   \\:\\  \\ /:/  / \\:\\/:/ /:/  / \n";
osout<<"  \\:\\  /:/  /   \\::/__/     \\:\\  /:/  /   \\::/ /:/  /  \n";
osout<<"   \\:\\/:/  /     \\:\\  \\      \\:\\/:/  /     \\/_/:/  /   \n";
osout<<"    \\::/  /       \\:\\__\\      \\::/  /        /:/  /    \n";
osout<<"     \\/__/         \\/__/       \\/__/         \\/__/     \n";
osout<<"\n";
osout<<"  ____                      __       __      _           __            \n";
osout<<" / __ \\_  _____ _____    __/ /  ___ / /_ _  (_)__  ___ _/ /_ __        \n";
osout<<"/ /_/ / |/ / -_) __/ |/|/ / _ \\/ -_) /  ' \\/ / _ \\/ _ `/ / // /        \n";
osout<<"\\____/|___/\\__/_/  |__,__/_//_/\\__/_/_/_/_/_/_//_/\\_, /_/\\_, /         \n";
osout<<"  / _ \\___  ___  ____                            /___/  /___/          \n";
osout<<" / ___/ _ \\/ _ \\/ __/                                                  \n";
osout<<"/_/___\\___/\\___/_/        __  _             ____         __            \n";
osout<<" / __ \\___  ___ _______ _/ /_(_)__  ___ _  / __/_ _____ / /____ __ _   \n";
osout<<"/ /_/ / _ \\/ -_) __/ _ `/ __/ / _ \\/ _ `/ _\\ \\/ // (_-</ __/ -_)  ' \\_ \n";
osout<<"\\____/ .__/\\__/_/  \\_,_/\\__/_/_//_/\\_, / /___/\\_, /___/\\__/\\__/_/_/_(_)\n";
osout<<"    /_/                           /___/      /___/                     \n";
osout<<"\n";
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
	for(constructor * i = &start_ctors; i != &end_ctors; i++){
		(*i)();
	}
}


extern "C" void kmain(const void* multiboot_struct, uint32_t magic_num) {
	gdt_install();
	printHelloMessage();
	
	while (1){
		delay(10000);
	};
}
