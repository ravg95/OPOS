.section .text
.extern irq_handler


.macro irq num
.global irq\num\()
irq\num\():
	cli
	push 0
	push $\num
	jmp common_handler_irq
.endm
            
irq 0
irq 1
irq 2
irq 3
irq 4
irq 5
irq 6
irq 7
irq 8
irq 9
irq 10
irq 11
irq 12
irq 13
irq 14
irq 15

common_handler_irq:
    # save registers
            pusha
            push %ds
            push %esp
    # call C++ Handler
           call irq_handler
           add %esp,4
    # restore registers
            pop %ds
            popa
            add %esp,8
            iret

#TODO FOR LOOP

