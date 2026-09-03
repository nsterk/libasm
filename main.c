#include "libasm/inc/libasm.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

static int write_errno;
static int ft_write_errno;

int main(void) {
	int fd1, fd2;
	printf(BACK_GRN" ft_strlen "RST"\n");

	char *string = "Momomomo\0";
	printf("%ld\n",ft_strlen(string));

	printf(BACK_GRN" ft_write "RST"\n");
	ssize_t ft_write_return = ft_write(1, "Momo\n", 5);
	printf("%li\n", ft_write_return);

	/*FT_WRITE */
	fd1 = open("test_file", O_RDONLY | O_CREAT);
	printf(GRN"Writing to a readonly file "RST"\n");
	ssize_t write_return = write(fd1, "hello", 2);
	write_errno = errno;
	printf("Write return value: %li	write errno: %i\n", write_return, write_errno);
	ft_write_return = ft_write(fd1, "hello", 2);
	ft_write_errno = errno;
	printf("ft_write return value: %li	ft_write errno: %i\n", ft_write_return, ft_write_errno);


    /*FT_READ*/
    printf(BACK_GRN" ft_read "RST"\n");
	fd1 = open("readText.txt", O_RDWR);
    fd2 = open("readText.txt", O_RDWR);
	char tmp[5] = "\0\0\0\0\0";
    char tmp2[5] = "\0\0\0\0\0";
	printf("Return value ft_read: %li\n", ft_read(fd1, tmp, 4));
    printf("Return value read: %li\n", read(fd2, tmp2, 4));
	printf("Bytes read by ft_read: %s\n", tmp);
    printf("Bytes read by read: %s\n", tmp2);

   	close(fd1);
	close(fd2);

	/*FT_STRCMP*/
    printf(BACK_GRN" ft_strcmp "RST"\n");
	const char *s1 = "Hello is it me you're looking for\0";
	const char *s2 = "Hello is it momo you're looking for\0";
	printf("returnv alue ft_strcmp: %i\n",ft_strcmp(s1, s2));

	/*FT_STRCPY*/
	printf(BACK_GRN" ft_strcpy "RST"\n");
	char tmp3[] = "momo\0";
	char tmp4[] = "\0\0\0\0\0\0\0\0";

	ft_strcpy(tmp4, tmp3);
	printf("strcpy des: %s\n", tmp4);

	/*FT_STRDUP */
	char *dupped = ft_strdup("c to the heck\0");
	printf("the dupped string: %s\n", dupped);
}
