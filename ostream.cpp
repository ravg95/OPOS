
#include "ostream.h"



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
			s<<str[i];
		}
		return s;
	}
	ostream& operator<<(ostream& s,const int i){
		//not implemented yet
	}
	ostream& operator<<(ostream& s,const char c){
		if(c == '\n'){
			s.x=0;
			s.y++;
		} else {
			s.VGA_buffer[WIDTH*s.y + s.x] = (s.VGA_buffer[WIDTH*s.y + s.x] & 0xFF00) | c;
			s.x++;
		}
		if(s.x>=WIDTH){
			s.x -= WIDTH;
			s.y++;
		}
		if(s.y>=HEIGHT){
			s.scroll_down();
			s.y--;
		}
		return s;
	}
	ostream& operator<<(ostream& s,const float f){
		//not implemented yet
		return s;
	}

	void ostream::scroll_down(){
		for(int i = 0; i<y*WIDTH;i+=WIDTH){
			for(int j=0; j <WIDTH ; j++){
				VGA_buffer[i +j] = VGA_buffer[i+WIDTH+j];
			}
			
		}
		
	}
