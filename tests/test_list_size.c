#include <libasm_tests.h>

void test_list_size() {
	printf("-------- %-10s --------\n", "ft_list_size");

	{
		t_list *head = NULL;

		for (int i = 0; i < 3; i++) {
			ft_list_new(&head, i);
		}

		printf("Test 1 - Size returned for a list with 3 elements: %i\n", ft_list_size(head));
		free_list(head);

	}

	printf("Test 2 - Size returned for empty list: %i\n", ft_list_size(NULL));

	/* This test takes a minute or so to run which is why it is commented out */
	
	// {
	// 	t_list *head = NULL;
	// 	int len = 100000;
	// 	for (int i = 0; i < len; i++) {
	// 		ft_list_new(&head, i);
	// 	}

	// 	printf("Size returned for a list with %i elements: %i\n", len, ft_list_size(head));
	// 	free_list(head);

	// }
}
