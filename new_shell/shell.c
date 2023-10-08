#include "main.h"
/**
 * loop_Functions - loops through the functions
 * @args: command-line arguments
 */
void loopFunctions(char **args)
{
	char *token = NULL;

	signal(SIGINT, handle_signal);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		token = read_line();
		args = _tokenize(&args, token);
		execute_cmd(args);

		free(token);
		free(args);
	}
}

/**
 * main - Entry point for simple_shell program.
 * Return: 0 on success, 1 on failure.
 */
int main(int ac __attribute__((unused)), char **args)
{
	loopFunctions(args);

	return (0);
}
