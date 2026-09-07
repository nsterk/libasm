; void	ft_list_push_front(t_list **begin_list, void *data);
; RDI = pointer to pointer to begin_list, RSI = pointer to data

extern malloc

global ft_list_push_front

ft_list_push_front:
	xor		rax, rax
	mov		r8, rdi		; RDI is callee saved so we need to store it. If our creation of a new list object succeeds, we'll want to change the value in RDI. But if not, we want to leave RDI unchanged
	mov		rdi, 16
	mov		r10, rsi
	call	malloc wrt ..plt
	cmp		rax, 0 		; check if malloc failed, if yes we need to return to avoid segfaulting
	je		.ret

	mov		qword [rax], r10	; Move the ptr to data, our 2nd argument, into the address returned by malloc. This address, wiht offset 0, will corerspond to element.data
	; Our new element needs to point to the original head. Right now we have a pointer to a pointer to the original head in r8. Derefencing r8 gives us a pointer to the original head. This value needs to be placed in new element.next, which is [rax + 8]
	; cant do memory to memory so need to move one of these dereferencing results into a register
	mov	r9, [r8]
	mov	[rax + 8], r9;

	; The new element has to become the new head. r8 contains the address of the pointer that points to the head. This pointer needs to now point at our new element. So we need to put the effective address of rax into [r8]
	lea	r9, [rax]
	mov [r8], rax

	.ret:
		mov rdi, r8
		ret
