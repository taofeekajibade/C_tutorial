#include "main.h"

int main(void)
{
	char *usercmd = NULL;
	char *token;
	char **args = NULL;
	size_t bufsize = 0;
	ssize_t char_read = 0;
	char *delim = " \n";
	int i = 0;

	while (1)
	{
		print_string("(Simple_Shell) $ "); /*prints prompt */
		char_read = getline(&usercmd, &bufsize, stdin);
		if (char_read == -1)
		{
			perror("getline");
			free(usercmd);
			return (-1);
		}
		/* handling basic commands */
		args = malloc(sizeof(char *) * bufsize);
		if (args == NULL)
		{
			perror("malloc");
			free(usercmd);
			return (-1);
		}

		/* Tokenize usercmd */
		token = strtok(usercmd, delim);
		while (token)
		{
			args[i] = strdup(token);
			token = strtok(NULL, delim);
			i++;
		}

		if (i > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				print_string("Goodbye...\n");
				break;
			}
			else if (strcmp(args[0], "cd") == 0)
			{
				if (i < 2)
				{
					print_string("Usage: cd <directory>");
				}
				else
				{
					if (chdir(args[1]) != 0)
					{
						perror("cd");
					}
				}
			}
			else
			{
				print_string("command not found\n");
			}
		}
		free(usercmd);
		free(args);
		usercmd = NULL;
		bufsize = 0;
	}
	return (0);
}
