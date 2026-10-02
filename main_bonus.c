#include <libasm_tests.h>
#include <stdlib.h>
// #include <fcntl.h>

// void test_list_size();
// void test_list_push_front();
// void test_atoi_base(void);
// void	test_list_remove_if(void);

// int	cmp(void *list_ptr_data, void *list_ptr_other_data) {
// 	return (*((int*)list_ptr_data) - *((int*)list_ptr_other_data));
// }


int main(void) {
	// test_list_size();
	// test_list_push_front();
	// test_atoi_base();
	// test_list_remove_if();

	t_list *head = ft_list_new(NULL, 3);
	t_list *tmp = NULL;
	// ft_list_new(&head, 8);
	// ft_list_new(&head, 6);
	ft_list_new(&head, 1);
	ft_list_new(&head, 9);
	print_list(head, "Before: ");
	ft_list_sort(&head, &cmp);
	print_list(head, "After:  ");
	while (head) {
		tmp = head;
		head = head->next;
		the_free_fct(tmp);
	}
	return (0);
}
