#include <libasm.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

void test_read() {
	int fd1, fd2;

    printf(BACK_GRN" ft_read "RST"\n");
	fd1 = open("readText.txt", O_RDWR);
    fd2 = open("readText.txt", O_RDWR);
	char tmp[] = "\0\0\0\0\0";
    char tmp2[] = "\0\0\0\0\0";
	printf("Return value ft_read: %li\n", ft_read(fd1, tmp, 4));
    printf("Return value read: %li\n", read(fd2, tmp2, 4));
	printf("Bytes read by ft_read: %s\n", tmp);
    printf("Bytes read by read: %s\n", tmp2);

   	close(fd1);
	close(fd2);
}