#include <libasm_tests.h>

void test_strcpy() {
	printf("\n-------- %-10s --------\n", "ft_strcpy");

	char tmp3[] = "momo";
	char tmp4[] = "aaaaaa";

	ft_strcpy(tmp4, tmp3);
	printf("strcpy des: %s\n", ft_strcpy(tmp4, tmp3));
}
