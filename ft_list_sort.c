// #include <libasm.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
	void					*data;
	struct s_list *next;
}								t_list;

int		list_size(t_list *head) {
	int i = 0;
	while (head) {
		i++;
		head = head->next;
	}
	return i;
}

int	cmp(void *list_ptr_data, void *list_ptr_other_data) {
	return (*((int*)list_ptr_data) - *((int*)list_ptr_other_data));
}

t_list	*ft_list_new(t_list **head, int data) {
	t_list *new = malloc(sizeof(t_list));
	int *num = malloc(sizeof(int));
	*num = data;
	new->data = num;
	new->next = NULL;	
	if (!head || !(*head)) return new;

	t_list *tmp = *head;
	while (tmp->next) tmp = tmp->next;
	
	tmp->next = new;
}

void print_list(t_list *head, char *msg) {
	printf("%s", msg);
	while (head) {
		printf("%i	", *(int*)(head->data));
		head = head->next;
	}
	printf("\n");
}

void	the_free_fct(void *node) {
	free(((t_list*)node)->data);
	free((t_list*)node);
}

int		is_sorted(t_list *head, int (*cmp)()) {
	while (head && head->next) {
		if (cmp(head->data, head->next->data) > 0) return 0;
		head = head->next;
	}
	return 1;
}

void ft_list_sort(t_list **begin_list, int (*cmp)()) {
	if (!begin_list || !(*begin_list) || list_size(*begin_list) < 2) return;
	t_list *tmp = NULL;
	void *tmp_data;

	while (!is_sorted(*begin_list, cmp)) {
		tmp = *begin_list;
		while (tmp && tmp->next) {
			if (cmp(tmp->data, tmp->next->data) > 0) {
				tmp_data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = tmp_data;
			}
			tmp = tmp->next;
		}
	}
}

int main(void) {
	t_list *head = ft_list_new(NULL, 3);
	t_list *tmp = NULL;
	ft_list_new(&head, 8); 
	ft_list_new(&head, 6);
	ft_list_new(&head, 1);
	ft_list_new(&head, 9);
	print_list(head, "Before: ");
	ft_list_sort(&head, &cmp);
	print_list(head, "After:  ");
	while (head) {
		tmp = head;
		head = head->next;
		the_free_fct(tmp);
	}
	return (0);
}