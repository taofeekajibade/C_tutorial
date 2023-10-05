#include "main.h"
/**
 * handle_setenv - sets the enviroment variable
 * @variable: environment variable name.
 * @value: environment variable value.
 * Return: 0 on success, or -1 on failure
 */
int handle_setenv(char **argv)
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
	}
	else
	{
		if (setenv(argv[1], argv[2], 1) == -1)
		{
			perror("hsh");
		}
	}
	return (0);
}

/**
 * handle_unsetenv - unsets the enviroment variable
 * @variable: environment variable name
 * Return: 0 on success, or -1 on failure
 */
int handle_unsetenv(char **argv)
{
	if (argv[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
	}
	else
	{
		if (unsetenv(argv[1]) == -1)
		{
			perror("hsh");
		}
	}
	return (0);
}
