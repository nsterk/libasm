#include <libasm_tests.h>

void check_equal(int expected, int got);

void test_atoi_base(void) {
	
	char *base16Lower = "0123456789abcdef";
	char *base16Upper = "0123456789ABCDEF";
	char *base10 = "0123456789";
	char *base2 = "01";
	char *empty = "";
	char *nope = NULL;
	char *dupBase = "1216";
	char *overflow = "3147483647";
	char *multipleSigns = "--520";
	char *lostSpaces = "   -    520";
	char *binary42 = "00101010";

	printf("\n-------- %-10s --------\n", "ft_atoi_base");

	printf(U_WHT"Invalid base strings"RST"\n");

	/* Test 1 */
	printf("Test 1 - Duplicates in base: ");
	check_equal(0, ft_atoi_base("1", dupBase));

	/* Test 2 */
	printf("Test 2 - Empty base: ");
	check_equal(0, ft_atoi_base("1", empty));

	/* Test 3 */
	printf("Test 3 - Base of size 1: ");
	check_equal(0, ft_atoi_base("1", "1"));

	printf(U_WHT"\nInvalid input strings\n"RST);

	/* Test 4 */
	printf("Test 4 - multiple sign characters present: ");
	check_equal(atoi(multipleSigns), ft_atoi_base(multipleSigns, base10));

	/* Test 5 */
	printf("Test 5 - unexpected space characters present: ");
	check_equal(atoi(lostSpaces), ft_atoi_base(lostSpaces, base10));

	printf(U_WHT"\nBase 10 conversions, comparing to atoi"RST"\n");

	/* Test 6 */
	printf("Test 6 - valid positive input sting: ");
	check_equal(atoi("123"), ft_atoi_base("123", base10));

	/* Test 7 */
	printf("Test 7 - valid negative input sting: ");
	check_equal(atoi("-123"), ft_atoi_base("-123", base10));

	/* Test 8 */
	printf("Test 8 - valid input string but overflow: ");
	check_equal(atoi (overflow), ft_atoi_base(overflow, base10));

	
	printf(U_WHT"\nBase 16"RST"\n");
	// 7DB2B8 = 8237752 in decimal
	/* Test 9 */
	printf("Test 9 - uppercase hexadecimal conversion: ");
	printf("ft_atoi_base(\"7DB2B8\", \"%s\") returns %i\n", base16Upper, ft_atoi_base("7DB2B8", base16Upper));

	/* Test 10 */
	printf("Test 10 - lowercase hexadecimal conversion: ");
	printf("ft_atoi_base(\"7db2b8\", \"%s\") returns %i\n", base16Lower, ft_atoi_base("7db2b8", base16Lower));

	printf(U_WHT"\nBase 2"RST"\n");
	//00101010 = 42 in decimal
	/* Test 11 */
	printf("Test 11 - Converting binary 42 (00101010) returns %i\n", ft_atoi_base(binary42, base2));

}
