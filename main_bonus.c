#include <libasm_tests.h>

void check_equal(int expected, int got) {
	if (expected != got) {
		printf(RED"KO"RST);
		printf("- expected %i, got %i\n", expected, got);
	} else printf(GRN"OK\n"RST);
}

int main(void) {
	test_list_size();
	test_list_push_front();
	test_atoi_base();
	test_list_remove_if();
	test_list_sort();
	return (0);
}
