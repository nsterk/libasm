#include <libasm_tests.h>
#include <fcntl.h>
#include <errno.h>

void check_equal(int expected, int got);

void test_read() {
	int fd1, fd2;

    printf("\n-------- %-10s --------\n", "ft_read");

	fd1 = open("tests/readText.txt", O_RDWR);
    fd2 = open("tests/readText.txt", O_RDWR);

	char ft_read_dest[] = "\0\0\0\0\0";
    char read_dest[] = "\0\0\0\0\0";

	/* Test 1 */
	printf("Test 1 - return value successful read: ");
	check_equal((int)read(fd2, read_dest, 4), (int)ft_read(fd1, ft_read_dest, 4));

	/* Test 2 */
	printf("Test 2 - comparing the actual bytes read: ");
	if (strcmp(read_dest, ft_read_dest)) {
		printf(RED"KO"RST);
		printf("Expected: %s	Got: %s\n", read_dest, ft_read_dest);
	} else printf(GRN"OK\n"RST);

   	close(fd1);
	close(fd2);

	/* Test 3 */
	printf("Test 3 - Invalid file descriptor: ");
	fd1 = -1;
	check_equal((int)read(fd1, read_dest, 4), (int)ft_read(fd1, ft_read_dest, 4));

	/* Test 4, stdin */
	char tmp[25] = {0};
	printf("Test 4 - stdin: \n");
	ft_read(0, tmp, 25);
	printf("Bytes read: %s\n", tmp);

}