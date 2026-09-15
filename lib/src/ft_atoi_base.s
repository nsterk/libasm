extern ft_strlen

global ft_atoi_base

ft_atoi_base:
	xor		rax, rax

	.validate_base_loop:
		; loop over rsi
		cmp	[rsi + rax], byte 0
		jne .check_and_increment

	cmp rax, 2
	jl	.set_invalid

.return:
	pop		rsi
	pop		rdi
	ret

.set_invalid:
	xor		rax, rax
	jmp		.return

.check_duplicates:
	mov		r8, rax
	xor		r9, r9

	xor		r8, r8
	.check_dups_loop:
		dec r8 ; This needs to be done at the start of the first iteration too because at this point the value in r8 is identical to the value in rax
		mov	r9b, [rsi + r8]
		cmp r9b, byte [rsi + rax]
		je	.set_invalid
		cmp r8, 0
		jne .check_dups_loop

.check_and_increment:
	cmp		rax, 0
	jne		check_duplicates
	jmp		.validate_base_loop