.set IRQ_BASE, 0x20

.section .text

.extern _ZN16InterruptManager15handleInterruptEhj
.global _ZN16InterruptManager22ignoreInterruptRequestEv

.macro handleException num
.global _ZN16InterruptManager16handleException\num\()Ev
_ZN16InterruptManager16handleException\num\()Ev:
	movb $\num, (interruptNumber)
	jmp int_bottom
.endm

.macro handleInterruptRequest num
.global _ZN16InterruptManager26handleInterruptRequest\num\()Ev
_ZN16InterruptManager26handleInterruptRequest\num\()Ev:
	movb $\num + IRQ_BASE, (interruptNumber)
	jmp int_bottom
.endm

handleInterruptRequest 0x00
handleInterruptRequest 0x01


int_bottom:

	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs

	pushl %esp
	push (interruptNumber)
	call _ZN16InterruptManager15handleInterruptEhj
	addl $5, %esp
	movl %eax, %esp
	
	popl %gs
	popl %fs
	popl %es
	popl %ds
	popa
	
_ZN16InterruptManager22ignoreInterruptRequestEv:
	
	iret
	
.data
	interruptNumber: .byte 0
