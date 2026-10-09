#include <libasm_tests.h>

#define MASSIVE	100000

void check_equal_string(char *expected, char *got);

void test_strcpy() {
	printf("-------- %-10s --------\n", "ft_strcpy");

	char ft_dest[10] = {'a'};
	char dest[10] = {'a'};

	char *string = "momo";
	char long_string[MASSIVE + 1];
	memset(long_string, '1', MASSIVE);
	long_string[MASSIVE] = '\0';

	/* Test 1 */
	printf("Test 1 - regular string: ");
	check_equal_string(ft_strcpy(ft_dest, string), strcpy(dest, string));

	/* Test 2 */
	printf("Test 2 - empty string: ");
	check_equal_string(ft_strcpy(ft_dest, ""), strcpy(dest, ""));

	/* Test 3 */
	char long_ft_dest[MASSIVE + 1];
	char long_dest[MASSIVE + 1];

	printf("Test 3 - very long string: ");
	check_equal_string(ft_strcpy(long_ft_dest, long_string), strcpy(long_dest, long_string));
}
