#include "main.h"
/**
 * print_env - prints environment variables
 * @env: argument environment path
 */

int print_env(char **env)
{
	int i;

	if (env == NULL)
	{
		return (-1);
	}

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
