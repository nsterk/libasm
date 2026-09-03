			global	momolen

momolen:
	xor		rax, rax
	push	rbp
	mov		rbp, rsp
	sub		rsp, 8 ; ptr 8 byte
	mov		[rbp - 8], rdi
.momoloop:
	cmp		[rdi], byte 0
	je		.return
	inc		rdi
	jmp		.momoloop
.return:
	mov 	rax, [rbp - 8]
	sub 	[rbp - 8], rdi
	mov		rdi, rax
	mov		rax, [rbp - 8]
	mov		rsp, rbp
	pop		rbp
	ret
	