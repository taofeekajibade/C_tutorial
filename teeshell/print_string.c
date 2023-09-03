#include "main.h"
/**
 * print_string - prints string
 * @str: string to print
 */
void print_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
}
