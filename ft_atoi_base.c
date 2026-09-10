#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s) {
	int i = 0;
	if (!s) return i;
	while (s && s[i]) {
		i++;
	}
	return i;
}

int	char_value(char c) {
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else {
		printf("%c\n", c);
		return 0;
	}
}

int ft_atoi_base(char *str, char *base) {
	int num = 0;
	int base_len = ft_strlen(base);
	int value;
	while ( str && *str >= base[0] && *str <= base[base_len - 1]) {
		value = char_value(*str);
		num = num * base_len + value;
		str++;
	}
	return num;
}

int main(int argc, char **argv) {
	if (argc < 3) {
		exit(0);
	}
	// printf("%i\n", ft_strlen("hohoho\0"));
	int ret = ft_atoi_base(argv[1], argv[2]);
	printf("conerting %s in base %s: %i\n", argv[1], argv[2], ret);
}