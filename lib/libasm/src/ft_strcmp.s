global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor r9, r9
	xor r10, r10
	
	strcmp.loop:
		mov r9b, [rdi]
		mov r10b, [rsi]
		cmp r9b, r10b
		jne	strcmp.done

		cmp	r10b, byte 0
		je	strcmp.done
		inc rdi
		inc rsi
		jmp strcmp.loop

	strcmp.done:
		sub r9, r10
		mov	rax, r9
		xor r9, r9
		ret
