#include <libasm.h>
#include <libasm_tests.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void test_strdup() {
	printf("\n-------- %-10s --------\n", "ft_strdup");

	{
		char *s = "Please duplicate me omg";
		char *dupped = ft_strdup(s);

		printf("The original string: %s\n", s);
		printf("the duplicated string: %s\n", dupped);
		free(dupped);
	}

}
