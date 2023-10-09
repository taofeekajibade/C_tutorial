#include "main.h"
/**
 * main - Entry point for simple_shell program.
 * @ac: argument count
 * @args: argument vectors
 * @env: environment variables
 *
 * Return: 0 on success, 1 on failure.
 */

int main(int ac, char **args, char **env)
{
	char *input;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);            

		input = readInput();

		/* Remove the newline character from the end of the input*/
		input[strcspn(input, "\n")] = '\0';
		/* Check if the input is not empty*/
		if (input != NULL)
		{
			_tokenize(input, &args);
			if (ac > 0)
			{
				executeCommand(ac, args, env);
			}
			_freedptr(args);
		}
	}
	return (0);
}
