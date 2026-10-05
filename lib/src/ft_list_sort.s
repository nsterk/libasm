; void	ft_list_sort(t_list **begin_list, int (*cmp)());
;	RDI = **begin_list, RSI == (*cmp)

;void ft_list_sort(t_list **begin_list, int (*cmp)()) {
;	if (!begin_list || !(*begin_list) || list_size(*begin_list) < 2) return;
;	t_list *tmp = NULL;
;	void *tmp_data;
;
;	while (!is_sorted(*begin_list, cmp)) {
;		tmp = *begin_list;
;		while (tmp && tmp->next) {
;			if (cmp(tmp->data, tmp->next->data) > 0) {
;				tmp_data = tmp->data;
;				tmp->data = tmp->next->data;
;				tmp->next->data = tmp_data;
;			}
;			tmp = tmp->next;
;		}
;	}
;}

extern	ft_list_size

global ft_list_sort

ft_list_sort:
	push	rbp
	mov		rbp, rsp

	; [rbp - 8 ]	t_list	*tmp
	; [rbp - 16] 	void 	*tmp->data
	; [rbp - 24]	t_list	*tmp->next	
	; [rbp - 32]	void	*tmp->next->data
	; [rbp - 40]	t_list	*begin_list
	; [rbp - 48]	function (*cmp)
	sub		rsp, 56
	
	cmp	rdi, 0x0
	je	.return
	cmp	qword [rdi], 0x0
	je	.return

	mov	r8, [rdi]
	mov	[rbp - 40], r8
	mov	[rbp - 48], rsi

	; Now we want to check if the list is bigger than 1. If not, we have to return
	mov		rdi, [rbp - 40]
	call	ft_list_size
	cmp		rax, 2
	jl		.return 

.init_check_sorted:
	mov	r8, [rbp - 40]
	mov [rbp - 8], r8	; tmp = *begin_list

.check_sorted:
	cmp	qword [rbp - 8], 0x0	; check if tmp is null. If it is that means the list is sorted, so return
	je	.return
	mov	r8, [rbp - 8]			; r8 = tmp
	cmp	qword [r8 + 8], 0x0		; check if tmp->next is null
	je	.return					; If it is then we have looped the entire list and all elements were sorted
	mov	r9, [r8]				; r9 = tmp->data
	mov [rbp - 16], r9			; [rbp - 16] = tmp->data
	mov	r9, [r8 + 8]			; r9 = tmp->next
	mov	[rbp - 24], r9			; [rbp - 24] = tmp->next
	mov	r9, [r9]				; r9 = tmp->next->data
	mov	[rbp - 32], r9			; [rbp - 32] = tmp->next->data

	; prepare the arguments for the cmp function
	mov	rdi, [rbp - 16]
	mov	rsi, [rbp - 32]

	; call the cmp function
	call [rbp - 48]
	js	.move_next_check_sorted 	; If the result of the previous calculation is negative it is in the correct order and we can move to next
	cmp rax, 0
	je	.move_next_check_sorted		; If the result is 0 also in correct order and we can move to next element 
	
	; If neither of the above checks apply it means the list is not sorted 
	jg	.init_tmp

	; tmp = tmp->next
.move_next_check_sorted:
	mov	r11, [rbp - 24]
	mov [rbp - 8], r11
	jmp	.check_sorted

.init_tmp:
	mov r8, [rbp - 40]	; tmp = *begin_list part 1
	mov [rbp - 8], r8	; tmp = *begin_list prt 2

.loop_list:
	cmp	qword [rbp - 8], 0x0	; check if tmp is null. If it is that means that we finished a sorting iteration and need to check if the list is sorted
	je	.init_check_sorted
	
	mov	r8, [rbp - 8]			; r8 = tmp
	cmp	qword [r8 + 8], 0x0		; check if tmp->next is null
	je	.init_check_sorted		; If it is then we have looped the entire list w our shitty sorting algorithm and ew need to check if the list is now sorted
	
	mov	r9, [r8]				; r9 = tmp->data
	mov [rbp - 16], r9			; [rbp - 16] = tmp->data
	mov	r9, [r8 + 8]			; r9 = tmp->next
	mov	[rbp - 24], r9			; [rbp - 24] = tmp->next
	mov	r9, [r9]				; r9 = tmp->next->data
	mov	[rbp - 32], r9			; [rbp - 32] = tmp->next->data

	; prepare the arguments for the cmp function
	mov	rdi, [rbp - 16]
	mov	rsi, [rbp - 32]

	call [rbp - 48]
	
	js .next_elem_loop_list

	; if rax < 0 we will be executing the following code before landing in .next_elem_loop_list. This is where we swap the elements' data


.swap_data:
	mov	r9, [rbp - 8]
	mov r10, [rbp - 32]
	mov	[r9], r10
	mov	r9, [rbp - 24]
	mov r10, [rbp - 16]
	mov	[r9], r10

.next_elem_loop_list:
	mov	r11, [rbp - 24]
	mov [rbp - 8], r11
	jmp	.loop_list

.return:
	mov	rsp, rbp
	pop	rbp
	ret
