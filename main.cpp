
#include "types.h"
#include "ostream.h"

void delay(int countdown_limit){
	volatile int w = 0;
		while(w<countdown_limit){
			w++;
		}
}

extern "C" void kmain(const void* multiboot_struct, uint32_t magic_num){
	ostream osout = ostream();
	for(int i = 0 ; i < 1000; i++){
		i%=127;
		osout<<"We are OS noobs: "<<(char)i<<'\n';
		delay(100000);
	}
	
	while(1);
}
