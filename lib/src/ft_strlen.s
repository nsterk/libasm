	global	ft_strlen

ft_strlen:
	xor		rax, rax
	push	rbp
	mov		rbp, rsp
	sub		rsp, 8
	mov		[rbp - 8], rdi

	.ft_strlen.loop:
		cmp		[rdi], byte 0
		je		.ft_strlen.return
		inc		rdi
		jmp		.ft_strlen.loop
		
	.ft_strlen.return:
		mov 	rax, [rbp - 8]
		sub 	rdi, [rbp - 8]
		mov		[rbp - 8], rax
		mov		rax, rdi
		mov		rsp, rbp
		pop		rbp
		ret
