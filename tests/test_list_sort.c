#include <libasm_tests.h>

void	test_list_sort(void) {
	printf("\n-------- %-10s --------\n", "ft_list_sort");
	
	{
		/* Test 1 */
		printf("Test 1 - Unsorted list with *int data\n");
		t_list *head = NULL;
		ft_list_new(&head, 3);
		ft_list_new(&head, 8);
		ft_list_new(&head, 6);
		ft_list_new(&head, 1);
		ft_list_new(&head, 9);
		print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		print_list(head, "After:  ");

		/* Test 2 */
		printf("\nTest 2 - Already sorted list\n");
		print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		print_list(head, "After:  ");
		free_list(head);
	}

	/* Test 3 */
	{
		printf("\nTest 3 - Unsorted list with char* data\n");
		t_list *head = ft_list_new_charptr(NULL, "abc");
		ft_list_new_charptr(&head, "zyx");
		ft_list_new_charptr(&head, "aac");
		print_char_list(head, "Before: ");
		ft_list_sort(&head, &ft_strcmp);
		print_char_list(head, "After:  ");
		free_list(head);
	}

	/* Test 4 */
	{
		printf("\nTest 4 - Contains duplicates: ");
		t_list *head = NULL;
		ft_list_new(&head, 3);
		ft_list_new(&head, 8);
		ft_list_new(&head, 6);
		ft_list_new(&head, 1);
		ft_list_new(&head, 8);
		// print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		// print_list(head, "After:  ");
		free_list(head);
		printf(GRN"OK\n"RST);
	}

	/* Test 5 */
	{
		printf("Test 5 - Empty list: ");
		t_list *head = NULL;
		// print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		// print_list(head, "After:  ");
		printf(GRN"OK\n"RST);
	}

	/* Test 6 */
	{
		printf("Test 6 - List of size 1: ");
		t_list *head = NULL;
		ft_list_new(&head, 3);
		// print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		// print_list(head, "After:  ");
		free_list(head);
		printf(GRN"OK\n"RST);
	}

	/* Test 7 */
	{
		printf("Test 7 - Null ptr as compare function pointer: ");
		t_list *head = NULL;
		ft_list_new(&head, 3);
		ft_list_new(&head, 1);
		// print_list(head, "Before: ");
		ft_list_sort(&head, NULL);
		// print_list(head, "After:  ");
		free_list(head);
		printf(GRN"OK\n"RST);
	}

}