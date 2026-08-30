			global	_start

			section	.text
_start:		mov		rax, 60
			push	word [var]
			pop		rdi
			syscall

			section .data
var:		db		99
