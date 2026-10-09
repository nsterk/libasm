#ifndef LIBASM_TESTS_H

# define LIBASM_TESTS_H

#define B_WHT			"\033[1;37m"
#define B_MAGENTA		"\033[1;35m"
#define B_PINK			"\033[1;38;2;250;0;100m"
#define B_TURQ			"\033[1;38;2;0;160;150m"
#define B_LILA			"\033[1;38;2;168;160;244m"

#define U_WHT			"\033[4;37m"

#define CYAN			"\033[36m"
#define MAGENTA			"\033[35m"
#define LILA			"\033[38;2;168;160;244m"
#define GRN				"\033[32m"
#define L_GRN			"\033[38;2;102;204;102m"
#define ORANGE			"\033[38;5;230;138;0m"
#define RED				"\033[38;5;124m"
#define PRETTY_RED		"\033[38;2;200;0;65m"
#define YELLOW			"\033[38;5;184m"
#define BLUE			"\033[38;5;33m"
#define BLUE2			"\033[38;2;0;143;151m"
#define INDG			"\033[38;2;10;85;102m"

#define BACK_GRN		"\033[30;42m"
#define BACK_WHT		"\033[30;47m"
#define BACK_CN			"\033[30;46m"

#define RST				"\033[0m"

/* ft_strlen large_len: also tested with yet another zero but at this point the real strlen as well as ft_strlen both get stack overflow */
#define LARGE_LEN 1000000

#include <libasm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_strlen();
void	test_write();
void	test_read();
void	test_strdup();
void	test_strcmp();
void	test_strcpy();

void	test_list_size(void);
void	test_list_push_front(void);
void	test_atoi_base(void);
void	test_list_remove_if(void);
void	test_list_sort(void);

t_list	*ft_list_new(t_list **head, int data);
t_list	*ft_list_new_charptr(t_list **head, char *data);
void	print_list(t_list *head, char *msg);
void	print_char_list(t_list *head, char *msg);
void	the_free_fct(void *node);
int		cmp(void *data, void *data_ref);
void	free_list(t_list *head);

#endif