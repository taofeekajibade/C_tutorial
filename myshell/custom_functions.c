#include "main.h"

void my_print(const char *str)
{
	int i;

    for (i = 0; str[i] != '\0'; i++)
	{
        write(STDOUT_FILENO, &str, 1);
    }
}
