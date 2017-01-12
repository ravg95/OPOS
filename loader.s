.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

.section .text


.global __idt_default_handler
.type __idt_default_handler, @function
__idt_default_handler:
	pushal
	mov $0x20, %al
	mov $0x20, %dx
	out %al, %dx
	#call _test
	popal
	iretl

.global _set_gdtr
.type _set_gdtr, @function
_set_gdtr:
	push %ebp
	movl %esp, %ebp

	lgdt 0x800

	movl %ebp, %esp
	pop %ebp
	ret

.global _set_idtr
.type _set_idtr, @function
_set_idtr:
	push %ebp
	movl %esp, %ebp

	lidt 0x10F0

	movl %ebp, %esp
	pop %ebp
	ret

.global _reload_segments
.type _reload_segments, @function
_reload_segments:
	push %ebp
	movl %esp, %ebp

	push %eax
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	pop %eax

	ljmp $0x8, $me
me:
	movl %ebp, %esp
	pop %ebp
	ret
	
.extern kmain
.extern callConstructors
.global loader


loader:
	mov $kstack, %esp
	
	call callConstructors
	
	push %eax
	push %ebx
	call kmain


_stop:
	cli
	hlt
	jmp _stop

.section .bss
.space 2*1024*1024
kstack:
