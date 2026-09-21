; void	ft_list_sort(t_list **begin_list, int (*cmp)());
; The function pointed to by cmp will be used as follows:
; (*cmp) ((list_ptr->data, other_list_ptr->data))

; gonna do ft_list_remove_if first

global ft_list_sort

ft_list_sort:
	xor rax, rax
	ret

