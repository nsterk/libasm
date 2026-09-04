global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor r9, r9
	xor r10, r10
	
	.cmp.loop:
		mov r9b, [rdi]
		mov r10b, [rsi]
		cmp r9b, r10b
		jne	.done

		cmp	r10b, 0
		je	.cmp.done
		inc rdi
		inc rsi
		jmp .cmp.loop

	.cmp.done:
		sub r9, r10
		mov	rax, r9
		xor r9, r9
		ret
