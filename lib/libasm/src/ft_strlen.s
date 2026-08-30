	global	ft_strlen

;ft_strlen:	xor		rax, rax				; if the xor operator is used on the same register, it sets the register to 0. So that's what we are doing here, just making sure that we start off with zero.
;			jmp		loop					; go to the code with label "loop". I.e.: start the counting loop
;loop:		cmp		[rdi + rax], byte 0		; is str[rax] b\0?
;			je		return					; if yes, jump to code with return label
;			inc		rax						; if no, we end up here. We are treating rax as our counter, and are incrementing it here.
;			jmp		loop					; go back to the start of the loop
;return:		ret								; since we used RAX as our counter register, we can return without moving something to RAX. The appropriate return value is already in RAX.


ft_strlen:		push	rbp			; maintain base pointer value by pushing it onto stack
				mov		rbp, rsp	; move value of stack pointer into base pointer register
				sub		rsp, 4		; When I pop the original value of edi off the stack I need somewhere to put it. I am allocating 4 bytes of space here
				push	rdi			; EDI is a callee-saved register, so we need to make sure we have the value saved.
				jmp		loop
loop:			cmp		[rdi], byte 0	; Is the value stored at the address stored at edi equal to 0? (= null terminator)
				je		return	;
				inc		rdi
return:			pop 	qword [rbp - 4]
				sub		rdi, [rbp - 4]
				mov		rax, rdi
				mov		rdi, [rbp - 4]
				pop		rbp

				