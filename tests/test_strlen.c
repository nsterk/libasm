#include <libasm.h>
#include <stdio.h>

void test_strlen() {
	printf(BACK_GRN" ft_strlen "RST"\n");
	char *string = "Momomomo\0";
	printf("len of str %s: %li\n", string, ft_strlen(string));
}
