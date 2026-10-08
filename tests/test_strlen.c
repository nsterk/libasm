#include <libasm.h>
#include <libasm_tests.h>

/* Also tested with yet another zero but at this point the real strlen as well as ft_strlen both get stack overflow*/
#define LARGE_LEN 1000000

void print_ret_fail(int expected, int got);

void test_strlen() {
	printf("*****		ft_strlen		 *****\n");

	int	ft_strlen_ret, strlen_ret;

	char *string = "Momomomo";
	char *null = NULL;
	char *empty = "";
	char long_string[LARGE_LEN + 1];
	memset(long_string, 'a', LARGE_LEN);
	long_string[LARGE_LEN] = '\0';
	
	/* Test 1 */
	printf("Test 1 - regular string: ");
	ft_strlen_ret = ft_strlen(string);
	strlen_ret = strlen(string);
	if (ft_strlen_ret != strlen_ret) {
		print_ret_fail(strlen_ret, ft_strlen_ret);
	} else printf(GRN"OK\n"RST);

	/* Test 2 */
	printf("Test 2 - empty string: ");
	ft_strlen_ret = ft_strlen(empty);
	strlen_ret = strlen(empty);
	if (ft_strlen_ret != strlen_ret) {
		print_ret_fail(strlen_ret, ft_strlen_ret);
	} else printf(GRN"OK\n"RST);

	/* Test 3 */
	printf("Test 3 - very long string: ");
	ft_strlen_ret = ft_strlen(long_string);
	strlen_ret = strlen(long_string);
	if (ft_strlen_ret != strlen_ret) {
		print_ret_fail(strlen_ret, ft_strlen_ret);
	} else printf(GRN"OK\n"RST);

	/* Commented out is a test with a null ptr. Strlen segfaults here. */

	// printf("Test 0 - null pointer: ");
	// ft_strlen_ret = ft_strlen(null);
	// strlen_ret = strlen(null);
	// if (ft_strlen_ret != strlen_ret) {
	// 	print_fail(strlen_ret, ft_strlen_ret);
	// } else printf(GRN"OK\n"RST);
}
