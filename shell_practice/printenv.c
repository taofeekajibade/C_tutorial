#include "main.h"
/**
 * print_env - prints environment variables
 * @env: argument environment path
 */
void print_env(char **env)
{
	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
