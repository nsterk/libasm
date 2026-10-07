; void	ft_list_push_front(t_list **begin_list, void *data);
; RDI = pointer to pointer to begin_list, RSI = pointer to data

extern malloc

global ft_list_push_front

ft_list_push_front:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 24
	mov		[rbp - 8], rdi	; RDI is callee saved so we need to store it. If our creation of a new list object succeeds, we'll want to change the value in RDI. But if not, we want to leave RDI unchanged
	mov		[rbp - 16], rsi

	xor		rax, rax
	mov		rdi, 16

	call	malloc wrt ..plt
	cmp		rax, 0 		; check if malloc failed, if yes we need to return to avoid segfaulting
	je		.return

	mov		r8, [rbp - 16]
	mov		qword [rax], r8	; Move the ptr to data, our 2nd argument, into the address returned by malloc. This address, wiht offset 0, will corerspond to element.data
	
	; Our new element needs to point to the original head. Right now we have a pointer to a pointer to the original head in [rbp - 8]. Derefencing r8 gives us a pointer to the original head. This value needs to be placed in new element.next, which is [rax + 8]
	; cant do memory to memory so need to move one of these dereferencing results into a register

	mov		r8, [rbp - 8]
	mov		r9, [r8]	; now a ptr to the old head is in r9
	mov		[r8], rax
	mov		r10, [r8]
	mov		[r10 + 8], r9

.return:
	mov	rsp, rbp
	pop	rbp
	ret
