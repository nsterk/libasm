#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>

void test_list_push_front() {
	t_list **head;
	
	int *num = malloc(sizeof(int));
	int *num2 = malloc(sizeof(int));
	void *omg;

	t_list *elem1 = malloc(sizeof(t_list));
	head = &elem1;
	*num = 88;
	elem1->data = (void*)num;
	elem1->next = NULL;

	*num2 = 99;
	omg = num2;
	printf("(*head)->data befoer list push fornt: %p\n", (*head)->data);
	printf("%i\n", *(int*)(*head)->data);
	ft_list_push_front(head, omg);
	printf("(*head)->data after list push fornt: %p\n", (*head)->data);
	printf("%i\n", *(int*)(*head)->data);
	printf("%i\n", *(int*)(*head)->next->data);
}