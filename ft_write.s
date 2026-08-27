			global ft_write

ft_write:	mov		rax, 1 	; The code for making a write call is 1. This needs to be placed in the rax register
			syscall			; Make the system call (because rax contains 1, that system call will be 'write')
			cmp		rax, 0 	; We will be able to find write's return value in RAX. We need to know if write failed, in which case the return value will be -1. This instruction compares the value in the RAX register to the value 0.
			jl		error	; If the result of the previous comparison is negative (== if value in RAX is less than 0), jump to the code section with label 'error'. This is becaus we will need to set the errno.
error:		