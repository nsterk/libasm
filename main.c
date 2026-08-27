#include "libasm.h"
#include <stdio.h>

int main(void) {
	char *string = "Momomomo\0";
	printf("%li\n", ft_strlen(string));
}