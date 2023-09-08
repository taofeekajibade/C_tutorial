#include "main.h"

void print_f(const char *str)
{
	int i;

    for (i = 0; str[i] != '\0'; i++)
	{
        write(STDOUT_FILENO, &str[i], 1);
    }
}
