#include <libasm.h>
#include <stdlib.h>
/**
TO DO ASSEMBLY CODE

- handle overflow

*/

/**

TO DO TESTS
- add invalid argument tests
- compare atoi_base using base 10 with regular atoi
*/


void test_atoi_base(void) {
	
	char *base16Lower = "0123456789abcdef";
	char *base16Upper = "0123456789ABCDEF";
	char *base10 = "0123456789";
	char *base2 ="01";
	char *empty = "";
	char *nope = NULL;
	char *dupBase = "1216";
	char *overflow = "3147483647";
	char *multipleSigns = "--520";
	char *lostSpaces = "   -    520";
	char *binary42 = "00101010";

	printf(GRN"ft_atoi_base "RST"\n");

	printf(U_WHT"Invalid base"RST"\n");
	
	printf("Duplicates in base:	ft_atoi_base(\"1\", \"%s\") returns %i\n",dupBase, ft_atoi_base("1", dupBase));
	printf("Empty base: 		ft_atoi_base(\"1\", \"%s\") returns %i\n", empty, ft_atoi_base("1", empty));
	printf("Base of size 1: 	ft_atoi_base(\"1\", \"1\") returns %i\n", ft_atoi_base("1", "1"));

	printf(U_WHT"Invalid str, using base10 and comparing with atoi"RST"\n");
	printf("Str = %s	\nft_atoi_base: %i	atoi: %i\n", multipleSigns, atoi (multipleSigns), ft_atoi_base(multipleSigns, base10));
	printf("Str = %s	\nft_atoi_base: %i	atoi: %i\n", lostSpaces, atoi (lostSpaces), ft_atoi_base(lostSpaces, base10));

	printf(U_WHT"Conversions with base 10, comparing to atoi"RST"\n");

	printf("atoi returns %i trying to convert %s\n", atoi(overflow), overflow);
	printf("ft_atoi_base returns %i trying to convert %s\n", ft_atoi_base(overflow, base10), overflow);

	printf("ft_atoi_base(\"12\", \"%s\") returns %i\n", base10, ft_atoi_base("12", base10));
	printf("ft_atoi_base(\"-12\", \"%s\") returns %i\n", base10, ft_atoi_base("-12", base10));
	
	printf(U_WHT"Base 16"RST"\n");
	// 7DB2B8 = 8237752 in decimal
	printf("ft_atoi_base(\"7DB2B8\", \"%s\") returns %i\n", base16Upper, ft_atoi_base("7DB2B8", base16Upper));
	printf("ft_atoi_base(\"7db2b8\", \"%s\") returns %i\n", base16Lower, ft_atoi_base("7db2b8", base16Lower));

	printf(U_WHT"Base 2"RST"\n");
	//00101010 = 42 in decimal
	printf("Converting binary 42 (00101010) returns: %i\n", ft_atoi_base(binary42, base2));

}
