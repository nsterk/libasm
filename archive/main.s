			global	_start

			section	.text
_start:		mov		rax, 1
			mov		rdi, 1
			mov		rsi, msg
			mov		rdx, 16
			syscall
			mov		rax, 60
			xor		rdi, rdi
			syscall

			section	.data
msg: 		db		"Momo is the love of my life", 10 ; in de tutorial heeft ie het over een new line maar das gewoon de int 10, das ascii newline