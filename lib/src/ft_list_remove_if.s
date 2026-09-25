; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
; RDI holds **begin_list, RSI holds *data_ref, RDX holds cmp ft ptr, RCX holds free ft ptr 

; The functions pointed to by cmp and free_fct will be used as:
; (*cmp)(list_ptr->data, data_ref);
; (*free_fct)(list_ptr->data);

;void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)) {
;	if (!begin_list || !(*begin_list)) return ;
;	t_list	*tmp = *begin_list;
;	
;	while (tmp && tmp->next) {
;		if (!(cmp(data_ref, tmp->next->data))) {
;			t_list *dup = tmp->next;
;			tmp->next = tmp->next->next;
;			free_fct(dup->data);
;			free_fct(dup);
;		}
;		tmp = tmp->next;
;
;	}
;	tmp = *begin_list;
;	if (tmp) {
;		if (!(cmp(data_ref, tmp->data))) {
;			*begin_list = tmp->next;
;			free_fct(tmp->data);
;			free_fct(tmp);
;		}
;	}
;}

global ft_list_remove_if

ft_list_remove_if:
	push	rbp
	mov		rbp, rsp

	; I want to allocate space for 5 pointers: *tmp [rbp - 8], *data_ref [rbp - 16], *cmp_function [rbp - 24], *free_function [rbp - 32], and *begin_list [rbp - 40]
	; So I need to subtract 40 from rsp
	; except that will cause stack misalignment so we have to subtract 48 instead
	sub		rsp, 48
	cmp		rdi, 0x0	; RDI should contain a pointer to a pointer. We need to check for null before attempting to derefence
	je		.return		

	mov		r8, [rdi]
	mov		[rbp - 8], r8		; rbp - 8 is where we store what in the C code is called "tmp"
	mov		[rbp - 40], r8		; We're gonna need to put different stuff RDI when we call the cmp and free functions, but we don't want to lose the ptr to begin_list cause we may have to reset it later (if the first element contains the data_ref)
	mov		[rbp - 16], rsi		; Move the ptr to data_ref into rbp - 16
	mov		[rbp - 24], rdx		; Move the ptr to the cmp function into rbp - 24
	mov		[rbp - 32], rcx		; Move the ptr to the free function into rbp - 32

.loop_body:
	mov		r8, [rbp - 8]	; I just want to be able to access tmp->next (the offset at +8), this is why I'm moving it into a register
	cmp		r8, 0x0			; Check that tmp is not null
	je		.check_head
	cmp		[r8 + 8], dword 0x0 	; R8 contains &tmp, so [R8 + 8] contains tmp->next. Check that tmp->next is not null
	je		.check_head

	; Now I need to prepare the arguments for the cmp function. Data_ref needs to go in RSI, tmp->data needs to go in RDI
	mov		rsi, [rbp - 16]
	mov		r12, [r8 + 8]	; The address of elem is not what i want to be putting into rdi for some reason. they are not the same. I want to see what happens when I pass the dereferenced value of [r8 + 8], instead of passin [r8 + 8]
	mov		rdi, [r12]
	;mov	rdi, [r8 + 8]
	call	[rbp - 24]
	cmp		rax, 0
	je		.remove_next_node

.move_to_next_node:
	mov	r8, [rbp - 8]
	mov	r9, [r8 + 8]
	mov [rbp - 8], r9
	jmp	.loop_body

.check_head:
	jmp	.return

.return:
	mov	rsp, rbp
	pop	rbp
	ret

.remove_next_node:
	mov		r8, [rbp - 8]	; r8 is a scratch register and we called another function in between. So it is technically possible for r8 to have been overwritten
	mov		r9, [r8 + 8]	; Store the node to delete (tmp->next) in r9
	mov		r10, [r9 + 8]	; We need to set tmp->next to tmp->next->next (because we will delete tmp->next). So we are storing tmp->next->next in r10
	mov		[r8 + 8], r10	; tmp->next = tmp->next->next
	mov		rdi, r9
	call	[rbp - 32]
	; TO DO error handling
	jmp	.move_to_next_node

