#include <stdio.h>
#include <libasm.h>
#include <libasm_tests.h>

void test_strcpy() {
	printf(GRN"\nft_strcpy\n"RST);
	char tmp3[] = "momo\0";
	char tmp4[] = "\0\0\0\0\0\0\0\0";

	ft_strcpy(tmp4, tmp3);
	printf("strcpy des: %s\n", tmp4);
}
