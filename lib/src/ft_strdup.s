extern malloc
extern ft_strcpy
extern ft_strlen

global	ft_strdup

ft_strdup:
	xor		rax, rax
	; nu moet ik rdi opslaan want ik moe iets anders in rdi doen voor malloc
	push	rdi
	call	ft_strlen
	mov		rdi, rax
	call	malloc wrt ..plt
	mov		rdi, rax
	pop		rsi
	call	ft_strcpy
	mov		rdi, rsi
	ret
