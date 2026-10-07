#include <stdlib.h>
#include <libasm_tests.h>

int	other_strlen(char *str) {
	int i = 0;
	while (str && str[i]) {
		i++;
	}
	return i;
}

void	other_strcpy(char *src, char *dst) {
	int i = 0;
	if (!src || !dst) return;
	while (src[i] && dst[i]) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

t_list	*ft_list_new(t_list **head, int data) {
	t_list *new = malloc(sizeof(t_list));
	int *num = malloc(sizeof(int));
	*num = data;
	new->data = num;
	new->next = NULL;	
	if (head && !(*head)) {
		*head = new;
		return new;
	}

	t_list *tmp = *head;
	while (tmp->next) tmp = tmp->next;
	
	tmp->next = new;
}

t_list	*ft_list_new_charptr(t_list **head, char *data) {
	int	strlen = other_strlen(data);
	t_list *new = malloc(sizeof(t_list));
	char *str = malloc((sizeof(char) * strlen) + 1);
	str[strlen] = '\0';
	other_strcpy(data, str);
	new->data = str;
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

void print_char_list(t_list *head, char *msg) {
	printf("%s", msg);
	while (head) {
		printf("%s	", (char*)(head->data));
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

void	free_list(t_list *head) {
	t_list	*tmp = NULL;

	while (head) {
		tmp = head;
		head = head->next;
		the_free_fct(tmp);
	}
}
