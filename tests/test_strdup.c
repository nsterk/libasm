#include <libasm.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void test_strdup() {
	printf(BACK_GRN" ft_strdup "RST"\n");

	char *dupped = ft_strdup("c to the heck\0");

	printf("the dupped string: %s\n", dupped);
	free(dupped);
}
