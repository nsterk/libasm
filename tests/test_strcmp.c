#include <stdio.h>
#include <libasm.h>
#include <string.h>

void test_strcmp() {
    printf(BACK_GRN" ft_strcmp "RST"\n");

	const char *s1 = "Hello\0";
	const char *s2 = "Hell\0";
	printf("	s1: %s	s2: %s\n", s1, s2);

	printf(GRN"Test 1: compare(s1, s2)\n"RST"ft_strcmp: %i	strcmp: %i\n",ft_strcmp(s1, s2), strcmp(s1, s2));
	printf(GRN"Test 2: compare(s2, s1)\n"RST"ft_strcmp: %i	strcmp: %i\n",ft_strcmp(s2, s1), strcmp(s2, s1));
	printf(GRN"Test 3: compare(s1, s1)\n"RST"ft_strcmp: %i	strcmp: %i\n",ft_strcmp(s1, s1), strcmp(s1, s1));
}
