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

	; t_list *tmp  			-> [rbp - 8]
	; void *tmp_data		-> [rbp - 16]
	; *begin_list ([rdi])	-> [rbp - 24]
	; (*cmp) (RSI)			-> [rbp - 32]
	sub		rsp, 32
	
	cmp	rdi, 0x0
	je	.return
	cmp	[rdi], 0x0
	je	.return

	mov	[rbp - 24], [rdi]
	mov	[rbp - 32], rsi

	; Now we want to check if the list is bigger than 1. If not, we have to return
	mov		rdi, [rbp - 24]
	call	ft_list_size
	cmp		rax, 2
	jl		.return 

.check_sorted:
	mov	[rbp - 8], [rbp - 24]	; tmp = *begin_list
	mov	r8,	[rbp - 8]			; I want to get to tmp->data, so ill need to dereference
	mov	r9, [r8]				; Now tmp->data is in r9
	mov	r10, [r8 + 8]			; Now a ptr to tmp->next is in r10
	mov	r10, [r10]


.init_tmp:
	mov	[rbp - 8], [rbp - 24]	; tmp = *begin_list

.loop_list:


.return:
	mov	rsp, rbp
	pop	rbp
	ret
