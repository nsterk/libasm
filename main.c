#include "libasm.h"
#include "../Unity/src/unity.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

static int write_errno;
static int ft_write_errno;

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_doBlahAndBlah(void) {
    //test stuff
}

void test_function_should_doAlsoDoBlah(void) {
    //more test stuff
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doBlahAndBlah);
    RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}

// int main(void) {
// 	int fd1, fd2;
// 	printf(BACK_GRN" ft_strlen "RST"\n");

// 	char *string = "Momomomo\0";
// 	// ft_strlen(string);

// 	printf(BACK_GRN" ft_write "RST"\n");
// 	ssize_t ft_write_return = ft_write(1, "Momo\n", 5);
// 	printf("%li\n", ft_write_return);

// 	/*FT_READ*/
// 	fd1 = open("readText.txt", O_RDWR);
// 	char tmp[9];
// 	tmp[8] = '\0';
// 	ft_read(fd1, tmp, 2);
// 	printf("%s\n", tmp);

// 	/*FT_WRITE */
// 	fd1 = open("test_file", O_RDONLY | O_CREAT);
// 	printf(GRN"Writing to a readonly file "RST"\n");
// 	ssize_t write_return = write(fd1, "hello", 2);
// 	write_errno = errno;
// 	printf("Write return value: %li	write errno: %i\n", write_return, write_errno);
// 	ft_write_return = ft_write(fd1, "hello", 2);
// 	ft_write_errno = errno;
// 	printf("ft_write return value: %li	ft_write errno: %i\n", ft_write_return, ft_write_errno);
// 	close(fd1);
// 	close(fd2);
// }