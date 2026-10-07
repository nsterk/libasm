#include <libasm.h>
#include <stdlib.h>
#include <libasm_tests.h>
#include <stdio.h>

void test_list_push_front() {
	t_list *head = NULL;
	ft_list_new(&head, 88);
	ft_list_new(&head, 1);
	
	int *num2 = malloc(sizeof(int));

	*num2 = 99;
	print_list(head, "Before: \n");
	ft_list_push_front(&head, num2);
	print_list(head, "After: \n");
	free_list(head);
}