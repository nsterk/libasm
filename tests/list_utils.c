#include <stdlib.h>
#include <libasm_tests.h>

t_list	*ft_list_new(t_list **head, int data) {
	t_list *new = malloc(sizeof(t_list));
	int *num = malloc(sizeof(int));
	*num = data;
	new->data = num;
	new->next = NULL;	
	if (!head || !(*head)) return new;

	t_list *tmp = *head;
	while (tmp->next) tmp = tmp->next;
	
	tmp->next = new;
}

void print_list(t_list *head, char *msg) {
	printf("%s", msg);
	while (head) {
		printf("%i	", *(int*)(head->data));
		head = head->next;
	}
	printf("\n");
}

void	the_free_fct(void *node) {
	free(((t_list*)node)->data);
	free((t_list*)node);
}

int	cmp(void *data, void *data_ref) {
	return (*((int*)data) - *((int*)data_ref));
}
