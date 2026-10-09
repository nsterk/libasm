#include <libasm_tests.h>

void check_equal_string(char *expected, char *got);

void test_strdup() {
	printf("\n-------- %-10s --------\n", "ft_strdup");

	char *string = "Please duplicate me omg";
	char long_string[LARGE_LEN + 1];
	memset(long_string, '1', LARGE_LEN);
	long_string[LARGE_LEN] = '\0';

	/* Test 1 */
	printf("Test 1 - regular string: ");
	char *ft_dupped = ft_strdup(string);
	char *dupped = strdup(string);

	check_equal_string(dupped, ft_dupped);

	free(ft_dupped);
	free(dupped);

	/* Test 2 */
	printf("Test 2 - empty string: ");
	ft_dupped = ft_strdup("");
	dupped = strdup("");

	check_equal_string(dupped, ft_dupped);

	free(ft_dupped);
	free(dupped);


	/* Test 3 */
	printf("Test 3 - very long string: ");
	ft_dupped = ft_strdup(long_string);
	dupped = strdup(long_string);

	check_equal_string(dupped, ft_dupped);

	free(ft_dupped);
	free(dupped);
}
