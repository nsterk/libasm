#include <libasm.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

static int write_errno;
static int ft_write_errno;

void test_write() {
	int fd1;

	printf(BACK_GRN" ft_write "RST"\n");
	ssize_t ft_write_return = ft_write(1, "Momo\n", 5);
	printf("%li\n", ft_write_return);

	fd1 = open("test_file", O_RDONLY | O_CREAT);
	printf(GRN"Writing to a readonly file "RST"\n");
	ssize_t write_return = write(fd1, "hello", 2);
	write_errno = errno;
	printf("Write return value: %li	write errno: %i\n", write_return, write_errno);
	ft_write_return = ft_write(fd1, "hello", 2);
	ft_write_errno = errno;
	printf("ft_write return value: %li	ft_write errno: %i\n", ft_write_return, ft_write_errno);

	close(fd1);
}
