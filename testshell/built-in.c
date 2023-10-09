#include "main.h"
/**
 * _fexit - A function to exit the shell.
 * @args: Double pointer to an array of strings.
 */
void _fexit(char **args)
{
	int i, status;

    if (args[1] != NULL)
    {
        for (i = 0; args[1][i]; i++)
        {
            if (!isdigit(args[1][i]))
            {
                write(2, INVALID_EXIT, sizeof(INVALID_EXIT) - 1);
                exit(EXIT_FAILURE);
            }
        }
        status = atoi(args[1]);

        if (status < 0 || status > 255)
        {
            write(2, OUT_OF_RANGE, sizeof(OUT_OF_RANGE) - 1);
            exit(EXIT_FAILURE);
        }
        exit(status);
    }
    else
    {
        exit(EXIT_SUCCESS);
    }
}