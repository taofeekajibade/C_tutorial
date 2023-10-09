#include "main.h"
/** final_loop - last iteration through the functions
 * @args: command-line arguments
 */
void final_loop(char **args)
{
	char *input = NULL;

	signal(SIGINT, handle_signal);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		input = read_line();
		args = _tokenize(&args, input);
		execute_cmd(args);

		free(args);
	}
}
/**
 * main - Entry point for simple_shell program.
 * Return: 0 on success, 1 on failure.
 */
int main(int ac, char **args)
{
	(void)ac;

	final_loop(args);

	_freedptr(args);

	return (0);
}
