#include "main.h"

char *readInput(void)
{
	char* input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        free(input);
    }
	return (input);
}