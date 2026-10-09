#include <fcntl.h>
#include <libasm_tests.h>

void check_equal(int expected, int got) {
	if (expected != got) {
		printf(RED"KO"RST);
		printf("- expected %i, got %i\n", expected, got);
	} else printf(GRN"OK\n"RST);
}

void check_equal_string(char *expected, char *got) {
	if (ft_strcmp(expected, got)) {
		printf(RED"KO"RST);
		printf("- expected %s, got %s\n", expected, got);
	} else printf(GRN"OK\n"RST);
}

int main(void) {
	test_strlen();
	test_write();
	test_read();
	test_strcmp();
	test_strdup();
	test_strcpy();
}
