; void	ft_list_sort(t_list **begin_list, int (*cmp)());
; The function pointed to by cmp will be used as follows:
; (*cmp) ((list_ptr->data, other_list_ptr->data))

; the cmp function will cast the void ptr to whatever is needed. So just write my tests with a cmp function that casts to integer and don't think about the void ptr casting beyond that

global ft_list_sort

ft_list_sort:
	xor rax, rax
	ret

