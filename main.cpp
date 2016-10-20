
#include "types.h"
#include "ostream.h"


extern "C" void kmain(const void* multiboot_struct, uint32_t magic_num){
	ostream osout = ostream();
	osout<<"posOS wita WAS!!";
	
	while(1);
}
