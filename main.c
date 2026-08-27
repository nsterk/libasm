#include "libasm.h"
#include <stdio.h>

int main(void) {
	printf(BACK_GRN" ft_strlen "RST"\n");

	char *string = "Momomomo\0";
	printf("%li\n", ft_strlen(string));

	printf(BACK_GRN" ft_write "RST"\n");
	ssize_t myWriteRet = ft_write(1, "Momo\n", 5);
	printf("%li", myWriteRet);
}