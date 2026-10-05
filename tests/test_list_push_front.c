#include <libasm.h>
#include <stdlib.h>
#include <libasm_tests.h>
#include <stdio.h>

void test_list_push_front() {
	t_list **head = NULL;
	
	int *num = malloc(sizeof(int));
	int *num2 = malloc(sizeof(int));

	t_list *elem1 = malloc(sizeof(t_list));
	head = &elem1;
	*num = 88;
	elem1->data = num;
	elem1->next = NULL;

	*num2 = 99;
	printf("(*head)->data befoer list push fornt: %p\n", (*head)->data);
	printf("%i\n", *(int*)(*head)->data);
	ft_list_push_front(head, num2);
	printf("(*head)->data after list push fornt: %p\n", (*head)->data);
	printf("%i\n", *(int*)(*head)->data);
	printf("%i\n", *(int*)(*head)->next->data);
}