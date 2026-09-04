#include <stdio.h>
#include <libasm.h>

void test_strcpy() {
	printf(BACK_GRN" ft_strcpy "RST"\n");
	char tmp3[] = "momo\0";
	char tmp4[] = "\0\0\0\0\0\0\0\0";

	ft_strcpy(tmp4, tmp3);
	printf("strcpy des: %s\n", tmp4);
}
