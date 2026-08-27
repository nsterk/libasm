extern __errno_location

			global ft_write

ft_write: 	mov		rax, 1 	; The code for making a write call is 1. This needs to be placed in the rax register
			syscall			; Make the system call (because rax contains 1, that system call will be 'write')
			cmp		rax, 0 	; We will be able to find write's return value in RAX. We need to know if write failed, in which case the return value will be -1. This instruction compares the value in the RAX register to the value 0.
			jl		error	; If the result of the previous comparison is negative (== if value in RAX is less than 0), jump to the code section with label 'error'. This is becaus we will need to set the errno.
			ret				;
error:		mov		rdx, rax	; We are going to call a function so will need to copy what was in RAX. We are storing it into RDX.
			neg		rdx			; the errno is set in the twos complement of the value in RAX. We moved the value to RDX, now we need to negate it. The result will be the errno value. Now we need to find the errno location so we can stoer this value in it
			call __errno_location wrt ..plt ; "Hello linux where is our errno stored?". See README for info on why we had to add wrt ..plt
			mov		[rax], rdx ; Errno location returns a pointer to a location. We will dereference it to obtain the location, and move the errno in there.
			mov		rax, -1 	; Write returns -1 upon error, and so must we. Right now the pointer to errno is in the return register, so we need set it back to -1
			ret