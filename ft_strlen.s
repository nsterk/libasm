	global	ft_strlen

ft_strlen:	xor		rax, rax	
			jmp		check
check:		cmp	[rdi + rax], byte 0
			je return
			inc rax
			jmp check
return:	ret
