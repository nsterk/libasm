#include <libasm_tests.h>
#include <libasm.h>
#include <stdlib.h>
// #include <fcntl.h>


int main(void) {
	test_list_size();
	test_list_push_front();
	test_atoi_base();
	test_list_remove_if();
	test_list_sort();
	return (0);
}
