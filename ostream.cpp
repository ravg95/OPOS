
#include "ostream.h"
#include "types.h"



	ostream::ostream(){
		VGA_buffer = (volatile uint16_t*)0xb8000;
		x=0;
		y=0;
		color = VGA_buffer[0] >> 8;
	}
	ostream::~ostream(){
		//empty - not much to destroy
	}
	ostream& operator<<(ostream& s,const char* str){
		for(int i = 0; str[i]!='\0'; i++){
			if(str[i] == '\n'){
				s.x=0;
				s.y++;
			} else {
			s.VGA_buffer[WIDTH*s.y + s.x] = (s.VGA_buffer[WIDTH*s.y + s.x] & 0xFF00) | str[i];
			s.x++;
			}
		}
		if(s.x>=WIDTH){
			s.x -= WIDTH;
			s.y++;
		}
		return s;
	}
	ostream& operator<<(ostream& s,const int i){
		return s;
	}
	ostream& operator<<(ostream& s,const char c){
		return s;
	}
	ostream& operator<<(ostream& s,const float f){
		return s;
	}

	void ostream::scroll_down(){
		
	}
