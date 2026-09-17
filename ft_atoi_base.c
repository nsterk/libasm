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

int	char_value(char c, char *base) {
	int i = 0;
	if (!base) return i;
	while (base[i]) {
		if (base[i] == c)
			return i;
		i++;
	}
	return -1;
}

int ft_atoi_base(char *str, char *base) {
	int num = 0;
	int base_len = ft_strlen(base);
	int value;
	int sign = 1;

	while ((*str >= 9 && *str <= 13 || *str == 32))
		str++;
	while (str) {
		value = char_value(*str, base);
		if (value < 0)
			break ;
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

	printf("atoi(\"----3\") returns %i\n", atoi("----33"));
	printf("atoi(\"\") returns %i\n", atoi(""));
	printf("atoi(\"-\") returns %i\n", atoi("-"));
	printf("atoi(\"+-\") returns %i\n", atoi("+-"));
	printf("atoi(\"+-1\") returns %i\n", atoi("+-1"));
	printf("atoi(\"-+1\") returns %i\n", atoi("-+1"));
	printf("atoi(\"+1\") returns %i\n", atoi("+1"));
	printf("atoi(\"         +1\") returns %i\n", atoi("         +1"));
	printf("atoi(\"         ++1\") returns %i\n", atoi("         ++1"));
	printf("atoi(\"+         1\") returns %i\n", atoi("+         1"));
}