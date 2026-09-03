			global	ft_strlen

ft_strlen:	xor		rax, rax				; if the xor operator is used on the same register, it sets the register to 0. So thats what we are doing here, just making sure that we start off with zero.
			jmp		loop					; go to the code with label "loop". I.e.: start the counting loop
loop:		cmp		[rdi + rax], byte 0		; is str[rax] 0?
			je		return					; if yes, jump to code with return label
			inc		rax						; if no, we end up here. We are treating rax as our counter, and are incrementing it here.
			jmp		loop					; go back to the start of the loop
return:		ret								; since we used RAX as our counter register, we can return without moving something to RAX. The appropriate return value is already in RAX.
