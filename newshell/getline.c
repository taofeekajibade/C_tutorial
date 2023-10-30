#include "main.h"
/**
 * read_input - function to read user command
 * Return: read command
 */
char *read_input(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
	{
        free(line);
        return (NULL);
    }
    return (line);
}
