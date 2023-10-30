#include "main.h"
/**
 * main - main function
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char **args;
	int status = 1;

	do
	{
		init_shell();

		line = read_input();
		if (line == NULL)
		{
			exit(EXIT_SUCCESS);
		}

		args = parse_input(line);
		if (args[0] != NULL)
		{
			execute_command(args);
		}

		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
