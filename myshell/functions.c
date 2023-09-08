#include "main.h"

void print_f(const char *str)
{
	int i;

    for (i = 0; str[i] != '\0'; i++)
	{
        write(STDOUT_FILENO, &str[i], 1);
    }
}

int str_cmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str1++;
	}
	return (*str1 - *str1);
}
