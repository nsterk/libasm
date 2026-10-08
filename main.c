#include <libasm.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <libasm_tests.h>

void test_strlen();
void test_write();
void test_read();
void test_strdup();
void test_strcmp();
void test_strcpy();

void print_ret_fail(int expected, int got) {
	printf(RED"KO"RST);
	printf("- expected %i, got %i\n", expected, got);
}

int main(void) {
	test_strlen();
	test_write();
	test_read();
	test_strcmp();
	test_strdup();
	test_strcpy();
}
