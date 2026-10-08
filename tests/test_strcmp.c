#include <libasm_tests.h>

void check_neg_pos(int expected, int got) {
	if (!expected) {
		if (got) {
			printf(RED"KO"RST);
			printf("- expected zero, got non-zero (%i)\n", got);
		} else printf(GRN"OK\n"RST);
	} else if (expected < 0) {
		if (got >= 0) {
			printf(RED"KO"RST);
			printf("- expected negative, got positive or zero (%i)\n", got);
		} else printf(GRN"OK\n"RST);
	} else {
		if (got <= 0) {
			printf(RED"KO"RST);
			printf("- expected positive, got negative or zero (%i)\n", got);
		} else printf(GRN"OK\n"RST);
	}
}

void test_strcmp() {
    printf("\n-------- %-10s --------\n", "ft_strcmp");

	const char *s1 = "ABC";
	const char *s2 = "AB";
	int ft_strcmp_ret, strcmp_ret;

	/* Test 1 */
	printf("Test 1 - compare(ABC, AB): ");
	ft_strcmp_ret = ft_strcmp(s1, s2);
	strcmp_ret = strcmp(s1, s2);
	check_neg_pos(strcmp_ret, ft_strcmp_ret);

	/* Test 2 */
	printf("Test 2 - compare(AB, ABC): ");
	ft_strcmp_ret = ft_strcmp(s2, s1);
	strcmp_ret = strcmp(s2, s1);
	check_neg_pos(strcmp_ret, ft_strcmp_ret);

	/* Test 3  */
	printf("Test 3 - compare(ABC, ABC): ");
	ft_strcmp_ret = ft_strcmp(s1, s1);
	strcmp_ret = strcmp(s1, s1);
	check_neg_pos(strcmp_ret, ft_strcmp_ret);

}
