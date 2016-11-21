#include "interrupts.h"
#include "ostream.h"


void keyboard_handler_main(void) {
	unsigned char status;
	char keycode;

	status = read_port(0x64);
	/* write EOI */
	write_port(0x20, 0x20);
	out<<"dfdjfnjnjnskncsdjncsdkcndsc\n\n\n\nfnddnsjkcndskncs\n";
	/* Lowest bit of status will be set if buffer is not empty */
	if (status & 0x01) {
		keycode = read_port(0x60);
		if(keycode < 0)
			return;
		out<<(char)keycode;
	}
}
