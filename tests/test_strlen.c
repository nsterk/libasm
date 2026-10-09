#include <libasm_tests.h>

void check_equal(int expected, int got);

void test_strlen() {
	printf("\n-------- %-10s --------\n", "ft_strlen");

	char *string = "Momomomo";
	char long_string[LARGE_LEN + 1];
	memset(long_string, 'a', LARGE_LEN);
	long_string[LARGE_LEN] = '\0';
	
	/* Test 1 */
	printf("Test 1 - regular string: ");
	check_equal(strlen(string), ft_strlen(string));

	/* Test 2 */
	printf("Test 2 - empty string: ");
	check_equal(strlen(""), ft_strlen(""));

	/* Test 3 */
	printf("Test 3 - very long string: ");
	check_equal(strlen(long_string), ft_strlen(long_string));

	/* Commented out is a test with a null ptr. Strlen segfaults here. */

	// printf("Test 0 - null pointer: ");
	//check_equal(strlen(NULL), ft_strlen(NULL));

}
