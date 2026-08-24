				global	_ft_strlen
; edi will contain the address to the str i need the length of
; im copyin the value onto the stack. So I can now ues the edi register for calculating. while the value at the address stored in edi is not 0, increment edi


				section	.text
_ft_strlen:		push	rbp			; maintain base pointer value by pushing it onto stack
				mov		ebp, esp	; move value of stack pointer into base pointer register
				sub		esp, 4		; When I pop the original value of edi off the stack I need somewhere to put it. I am allocating 4 bytes of space here
				push	edi			; EDI is a callee-saved register, so we need to make sure we have the value saved.
				jmp		check

check:			cmp		[edi], 0	; Is the value stored at the address stored at edi equal to 0? (= null terminator)
				jne		increment	; if not, jump to the section 'increment'

increment:		inc		edi
				jmp		check
				