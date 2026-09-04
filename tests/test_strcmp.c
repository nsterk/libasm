#include <stdio.h>
#include <libasm.h>

void test_strcmp() {
    printf(BACK_GRN" ft_strcmp "RST"\n");

	const char *s1 = "Hello is it me you're looking for\0";
	const char *s2 = "Hello is it momo you're looking for\0";

	printf("return value ft_strcmp: %i\n",ft_strcmp(s1, s2));
}