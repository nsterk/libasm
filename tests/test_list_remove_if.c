#include <libasm.h>
#include <libasm_tests.h>
#include <stdlib.h>

void	test_list_remove_if(void) {
	printf(GRN"ft_list_remove_if\n"RST);
	printf(U_WHT"List contains data_ref at start, middle, and end\n"RST);
	int data_ref = 1;
	t_list *head = ft_list_new(NULL, 1);
	t_list *tmp;
	for (int i = 0; i < 3; i++) {
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

	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
}
