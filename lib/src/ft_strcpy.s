	global	ft_strcpy

ft_strcpy:
	mov rax, rdi
	xor r9, r9
	xor r10, r10

	strcpy.loop:
		mov r9b, [rsi + r10]
		mov [rdi + r10], r9b

		cmp r9b, 0
		je strcpy.done
		inc	r10
		jmp strcpy.loop

	strcpy.done:
		xor r9, r9
		xor r10, r10
		ret
