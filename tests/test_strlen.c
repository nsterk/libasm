#include <libasm.h>
#include <libasm_tests.h>
#include <stdio.h>

void test_strlen() {
	printf(GRN"\nft_strlen\n"RST);

	char *string = "Momomomo";
	char *null = NULL;
	char *empty = "";
	 
	printf("len of str %s: %li\n", string, ft_strlen(string));
}
