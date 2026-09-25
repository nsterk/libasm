#include <libasm.h>
#include <stdlib.h>
// #include <fcntl.h>

// void test_list_size();
// void test_list_push_front();
// void test_atoi_base(void);

int	cmp(void *data, void *data_ref) {
	printf("***** cmp function ***** \n");
	// int base2 = *(int*)base;
	int data_int = *((int*)data);
	int data_ref_int = *((int*)data_ref);
	printf("data_int: %i		data_ref_int: %i\n", data_int, data_ref_int);

	// printf("base: %i	check): %i\n", check2, base2);
	return (data_int - data_ref_int);
}

t_list	*ft_list_new(t_list **head, int data) {
	t_list *new = malloc(sizeof(t_list));
	int *num = malloc(sizeof(int));
	// printf("%i 	%p \n", data, num);
	*num = data;
	new->data = num;
	new->next = NULL;	
	if (!head || !(*head)) return new;

	t_list *tmp = *head;
	while (tmp->next) tmp = tmp->next;
	
	tmp->next = new;
}

void print_list(t_list *head) {
	printf("---- list start ----\n");
	while (head) {
		printf("%i	\n", *(int*)(head->data));
		head = head->next;
	}
	printf("---- list end ----\n");
}

void	the_free_fct(void *node) {
	free(((t_list*)node)->data);
	free((t_list*)node);
}


int main(void) {
	// test_list_size();
	// test_list_push_front();
	// test_atoi_base();
	int two = 2;
	t_list *head = ft_list_new(NULL, 0);
	for (int i = 1; i < 4; i++) {
		ft_list_new(&head, i);
	}
	// ft_list_new(&head, 1);
	print_list(head);
	ft_list_remove_if(&head, &two, &cmp, &the_free_fct);
	print_list(head);
	return (0);
}
