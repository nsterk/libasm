#include <libasm.h>
#include <stdlib.h>

int	cmp(void *data, void *data_ref) {
	return (*((int*)data) - *((int*)data_ref));
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
	// printf("&head: %p\n", head);
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

void	test_list_remove_if(void) {
	printf(GRN"ft_list_remove_if\n"RST);
	printf(U_WHT"List contains data_ref at start, middle, and end\n"RST);
	int data_ref = 1;
	t_list *head = ft_list_new(NULL, 1);
	t_list *tmp;
	for (int i = 0; i < 3; i++) {
		// if (i == 4) ft_list_new(&head, 1);
		ft_list_new(&head, i);
	}
	ft_list_new(&head, 1);
	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
	while (head) {
		tmp = head;
		head = head->next;
		the_free_fct(tmp);
	}

	printf(U_WHT"List contains only data_ref\n"RST);
	head = ft_list_new(NULL, 1);

	for (int i = 0; i < 3; i++) {
		ft_list_new(&head, 1);
	}
	ft_list_new(&head, 1);
	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
	while (head) {
		tmp = head;
		head = head->next;
		the_free_fct(tmp);
	}

	printf(U_WHT"List does not contain data_ref\n"RST);
	head = ft_list_new(NULL, 99);

	for (int i = 0; i < 3; i++) {
		ft_list_new(&head, i + 99);
	}
	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
	while (head) {
		tmp = head;
		head = head->next;
		the_free_fct(tmp);
	}

	printf(U_WHT"Empty list\n"RST);
	head = NULL;

	// for (int i = 0; i < 3; i++) {
	// 	ft_list_new(&head, i + 99);
	// }
	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
	// while (head) {
	// 	tmp = head;
	// 	head = head->next;
	// 	the_free_fct(tmp);
	// }
}