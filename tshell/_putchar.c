#include "unistd.h"

void _putchar(char c)
{
	write(1, &c, 1);
}


void print_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
	}
}
