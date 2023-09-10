#include "main.h"

int main(void)
{
	char *usercmd = NULL;
	char *token;
	char **args = NULL;
	size_t bufsize = 0;
	ssize_t char_read = 0;
	char *delim = " \n";
	int i;

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

		token = strtok(usercmd, delim);
		while (token)
		{
			args[i] = strdup(token);
			token = strtok(NULL, delim);
			i++;
		}
		if (args != NULL && strcmp(args[0], "exit") == 0) /* handles exit */
		{
			print_string("Goodbye...\n");
			break;
		}
		else if (args != NULL && strcmp(args[0], "cd") == 0) /* handles 'cd' */
		{
			print_string("Usage: cd <directory>\n");
		}
		else
		{
			if(chdir(*args) != 0)
			{
				perror("cd");
			}
			while (args != NULL)
			{
				print_string("command not found\n");
				token = strtok(NULL, delim);
			}
		}
		free(usercmd);
		free(args);
		usercmd = NULL;
		bufsize = 0;
	}
	return (0);
}
