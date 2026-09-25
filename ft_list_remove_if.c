#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// typedef struct	s_list {
// 	void			*data;
// 	struct s_list	*next;
// }				t_list;

int	cmp(int *base, int *check) {
	return (*check - *base);
}

void	ft_list_new(t_list **head, int data) {
	t_list *new = malloc(sizeof(t_list));
	int *num = malloc(sizeof(int));
	*num = data;
	new->data = num;
	t_list *tmp = *head;
	while (tmp->next) tmp = tmp->next;
	tmp->next = new;
}

void print_list(t_list *head) {
	printf("---- list start ----\n");
	while (head) {
		printf("%i	\n", *(int*)(head->data));
		head = head->next;
	}
	printf("---- list end ----\n");
}

void	the_free_fct(t_list *node) {
	free(node->data);
	free(node);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)) {
	if (!begin_list || !(*begin_list)) return ;
	t_list	*tmp = *begin_list;
	
	while (tmp && tmp->next) {
		if (!(cmp(data_ref, tmp->next->data))) {
			t_list *dup = tmp->next;
			tmp->next = tmp->next->next;
			free_fct(dup->data);
			free_fct(dup);
		}
		tmp = tmp->next;

	}
	tmp = *begin_list;
	if (tmp) {
		if (!(cmp(data_ref, tmp->data))) {
			*begin_list = tmp->next;
			free_fct(tmp->data);
			free_fct(tmp);
		}
	}
}

int	main(void) {
	t_list *elem = malloc(sizeof(t_list));
	int *num = malloc(sizeof(int));
	*num = 2;
	int two = 2;
	elem->data = num;
	elem->next = NULL;
	// print_list(elem);
	for (int i = 0; i < 4; i++) {
		ft_list_new(&elem, i);
	}
	ft_list_new(&elem, 2);
	print_list(elem);
	ft_list_remove_if(&elem, &two, &cmp, &the_free_fct);
	print_list(elem);
}