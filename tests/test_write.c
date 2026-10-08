#include <libasm_tests.h>
#include <fcntl.h>
#include <errno.h>

static int write_errno;
static int ft_write_errno;

void check_equal(int expected, int got);

void test_write() {
	printf("\n-------- %-10s --------\n", "ft_write");

	int fd1;
	ssize_t ft_write_return, write_return;
	char *str = "Momo";

	/* Test 1 */
	printf("Test 1 - writing to file with permissions: ");
	fd1 = open("write_test_file", O_RDWR | O_CREAT);
	ft_write_return = ft_write(fd1, str, 4);
	write_return = write(fd1, str, 4);
	close(fd1);

	check_equal(write_return, ft_write_return);

	/* Test 2 */
	printf("Test 2 - return value failed write call: ");
	fd1 = open("write_no_permissions_file", O_RDONLY | O_CREAT);

	write_return = write(fd1, "hello", 2);
	write_errno = errno;

	ft_write_return = ft_write(fd1, "hello", 2);
	ft_write_errno = errno;

	check_equal(write_return, ft_write_return);

	/* Test 3 */
	printf("Test 3 - errno failed write call: ");
	check_equal(write_errno, ft_write_errno);

	close(fd1);

	/* Test 4 */
	printf("Test 4 - writing \"Momo\" to stdout: \n");

	ft_write(1, "Momo", 4);
}
