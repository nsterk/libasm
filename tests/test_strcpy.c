#include <libasm_tests.h>

void check_equal_string(char *expected, char *got);

void test_strcpy() {
	printf("\n-------- %-10s --------\n", "ft_strcpy");

	char ft_dest[10] = {'a'};
	char dest[10] = {'a'};

	char *string = "momo";
	char long_string[LARGE_LEN + 1];
	memset(long_string, '1', LARGE_LEN);
	long_string[LARGE_LEN] = '\0';

	/* Test 1 */
	printf("Test 1 - regular string: ");
	check_equal_string(strcpy(dest, string), ft_strcpy(ft_dest, string));

	/* Test 2 */
	printf("Test 2 - empty string: ");
	check_equal_string(strcpy(dest, ""), ft_strcpy(ft_dest, ""));

	/* Test 3 */
	char long_ft_dest[LARGE_LEN + 1];
	char long_dest[LARGE_LEN + 1];

	printf("Test 3 - very long string: ");
	check_equal_string(strcpy(long_dest, long_string), ft_strcpy(long_ft_dest, long_string));
}
