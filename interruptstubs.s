.section .text


.extern keyboard_handler_main

.global load_idt

.global keyboard_handler

.global read_port
.global write_port

load_idt:
	mov 4(%esp), %edx
	lidt (%edx)
	sti
	ret

keyboard_handler:                 
	call keyboard_handler_main
	#iret
	
read_port:
	movl 4(%esp), %edx
	inb  %dx, %al	
	ret

write_port:
	movl   4(%esp), %edx
	movb   8(%esp), %al
	outb   %al, %dx  
	ret
