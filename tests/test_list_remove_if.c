#include <libasm.h>
#include <libasm_tests.h>
#include <stdlib.h>

void	test_list_remove_if(void) {
	printf("\n-------- %-10s --------\n", "ft_list_remove_if");

	/* Test 1 */
	printf("Test 1 - List contains data_ref at start, middle, and end\n");
	int data_ref = 1;
	t_list *head = NULL;
	ft_list_new(&head, 1);
	t_list *tmp;
	for (int i = 0; i < 3; i++) {
		ft_list_new(&head, i);
	}
	ft_list_new(&head, 1);
	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
	free_list(head);

	/* Test 2 */
	printf("\nTest 2 - List contains only data_ref\n"RST);
	head = NULL;
	ft_list_new(&head, 1);

	for (int i = 0; i < 3; i++) {
		ft_list_new(&head, 1);
	}
	ft_list_new(&head, 1);
	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
	free_list(head);

	/* Test 3 */
	printf("\nTest 3 - List does not contain data_ref\n"RST);
	head = NULL;
	ft_list_new(&head, 99);

	for (int i = 0; i < 3; i++) {
		ft_list_new(&head, i + 99);
	}
	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
	free_list(head);

	/* Test 4 */
	printf("\nTest 4 - Empty list\n");
	head = NULL;

	print_list(head, "Before: ");
	ft_list_remove_if(&head, &data_ref, &cmp, &the_free_fct);
	print_list(head, "After:  ");
}
