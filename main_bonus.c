#include <libasm.h>
// #include <stdlib.h>
// #include <fcntl.h>

// void test_list_size();
// void test_list_push_front();
//void test_atoi_base(void);

int main(void) {
	// test_list_size();
	// test_list_push_front();
	// test_atoi_base();
	// printf("ft_atoi_base(\"12\", \"0123456789\") returns %i\n",ft_atoi_base("12", "0123456789"));
	char *base16Lower = "0123456789abcdef";
	char *base16Upper = "0123456789ABCDEF";
	char *base10 = "0123456789";

	// 7DB2B8 = 8237752 in decimal
	printf("ft_atoi_base(\"7DB2B8\", \"%s\") returns %i\n", base16Upper, ft_atoi_base("7DB2B8", base16Upper));
	printf("ft_atoi_base(\"7db2b8\", \"%s\") returns %i\n", base16Lower, ft_atoi_base("7db2b8", base16Lower));
	// ft_atoi_base("-12", "0123456789");
}
