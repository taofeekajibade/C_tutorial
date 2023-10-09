#include "main.h"


int main(int ac, char **args, char **env)
{
	char* input;
	int i;

	signal(SIGINT, handle_signal);

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, "$ ", 2);
			input = readInput();
			/* Remove the newline character from the end of the input*/
			input[strcspn(input, "\n")] = '\0';
			/* Check if the input is not empty*/
			if (input != NULL)
			{
				tokenize(input, &ac, &args);
				if (ac > 0)
				{
					executeCommand(ac, args, env);
				}
				_freedptr(args);
			}
			/*free(input);*/
		}
	}
	else
	{
		if (ac > 1)
		{
			for (i = 1; i < ac; i++)
			{
				input = args[i];
				tokenize(input, &ac, &args);
				executeCommand(ac, args, env);
				free(args);
			}
		}
	}
	return (0);
}
