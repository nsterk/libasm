#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>
#include <libasm_tests.h>

void	test_list_sort(void) {
	printf(GRN"ft_list_sort\n"RST);
	/* UNSORTED LIST WITH *INT DATA */
	{
		printf(U_WHT"Unsorted list with *int data\n"RST);
		t_list *head = NULL;
		ft_list_new(&head, 3);
		ft_list_new(&head, 8);
		ft_list_new(&head, 6);
		ft_list_new(&head, 1);
		ft_list_new(&head, 9);
		print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		print_list(head, "After:  ");

		printf(U_WHT"Already sorted list\n"RST);
		print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		print_list(head, "After:  ");
		free_list(head);
	}

	/* UNSORTED LIST WITH *CHAR DATA*/
	{
		printf(U_WHT"Unsorted list with char*data\n"RST);
		t_list *head = ft_list_new_charptr(NULL, "abc");
		ft_list_new_charptr(&head, "zyx");
		ft_list_new_charptr(&head, "aac");
		print_char_list(head, "Before: ");
		ft_list_sort(&head, &ft_strcmp);
		print_char_list(head, "After:  ");
		free_list(head);
	}

	/* DUPLICATES */
	{
		printf(U_WHT"Contains duplicates\n"RST);
		t_list *head = NULL;
		ft_list_new(&head, 3);
		ft_list_new(&head, 8);
		ft_list_new(&head, 6);
		ft_list_new(&head, 1);
		ft_list_new(&head, 8);
		print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		print_list(head, "After:  ");
		free_list(head);
	}

	/* EMPTY LIST */
	{
		printf(U_WHT"Empty list\n"RST);
		t_list *head = NULL;
		print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		print_list(head, "After:  ");
	}

	/* LIST OF SIZE 1 */
	{
		printf(U_WHT"List of size 1\n"RST);
		t_list *head = NULL;
		ft_list_new(&head, 3);
		print_list(head, "Before: ");
		ft_list_sort(&head, &cmp);
		print_list(head, "After:  ");
		free_list(head);
	}

	/* NULL PTR AS COMPARE FUNCTION PTR */
	{
		printf(U_WHT"Null ptr as compare function pointer\n"RST);
		t_list *head = NULL;
		ft_list_new(&head, 3);
		ft_list_new(&head, 1);
		print_list(head, "Before: ");
		ft_list_sort(&head, NULL);
		print_list(head, "After:  ");
		free_list(head);
	}

}