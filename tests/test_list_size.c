#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>

void test_list_size() {
	t_list head;
	t_list belly;
	t_list tail;
	int num = 1;

	head.data = &num;
	head.next = &belly;
	belly.data = &num;
	belly.next = &tail;
	tail.data = &num;
	tail.next = NULL;

	printf(BACK_GRN" ft_list_size "RST"\n");
	int listsize = ft_list_size(&head);
	printf("Size returned for a list with 3 elements: %i\n", listsize);
	printf("Size returned for empty list: %i\n", ft_list_size(NULL));


}
