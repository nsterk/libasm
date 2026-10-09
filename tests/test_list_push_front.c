#include <libasm.h>
#include <stdlib.h>
#include <libasm_tests.h>
#include <stdio.h>

void test_list_push_front() {
	printf("-------- %-10s --------\n", "ft_list_push_front");
	
	/* Test 1 */
	printf("Test 1: list contains elements\n");
	t_list *head = NULL;
	ft_list_new(&head, 88);
	ft_list_new(&head, 1);
	
	int *num2 = malloc(sizeof(int));

	*num2 = 99;
	print_list(head, "Before: \n");
	ft_list_push_front(&head, num2);
	print_list(head, "After: \n");
	free_list(head);

	/* Test 2 - Empty list */
	printf("\nTest 2: empty list\n");
	head = NULL;
	num2 = malloc(sizeof(int));
	*num2 = 99;
	print_list(head, "Before: \n");
	ft_list_push_front(&head, num2);
	print_list(head, "After: \n");
	free_list(head);
}