extern ft_strlen

global ft_atoi_base

ft_atoi_base:
	push	rdi
	push	rsi
	jmp		.validate_base
	pop		rsi
	pop		rdi
	ret

.validate_base:
	mov		rdi, rsi
	call 	ft_strlen
	cmp		rax, 0
	je		.set_invalid

.set_invalid:
	xor		rax, rax


