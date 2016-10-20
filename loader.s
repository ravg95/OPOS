.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

.section text
.extern kmain
.global loader


loader:
	mov $kstack, %esp
	push %eax
	push %ebx
	call kmain


_stop:
	cli
	hlt
	jmp _stop

.section bss
.space 4*1024*1024
kstack:
