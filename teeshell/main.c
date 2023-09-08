#include "main.h"

int main(void)
{
	char *usercmd = NULL;
	char *token;
	size_t bufsize = 0;
	ssize_t line_read = 0;

	while (1)
	{
		print_string("(Simple_Shell) $ "); /*prints prompt */
		line_read = getline(&usercmd, &bufsize, stdin);
		if (line_read == -1)
		{
			perror("Error reading input...");
			free(usercmd);
			return (-1);
		}
		/* handling basic commands */

		token = strtok(usercmd, " \n");
		if (token != NULL && strcmp(token, "exit") == 0) /* handles exit */
		{
			print_string("Goodbye...");
			break;
		}
		else if (token != NULL && strcmp(token, "cd") == 0) /* handles 'cd' */
		{
			token = strtok(NULL, " \n");
			if (token == NULL)
			{
				print_string("Usage: cd <directory>\n");
			}
			else
			{
				if(chdir(token) != 0)
				{
					perror("cd");
				}
			}
		}

		{
			while (token != NULL)
			{
				print_string("command not found\n");
				token = strtok(NULL, " \n");
			}
		}
		free(usercmd);
		usercmd = NULL;
		bufsize = 0;
	}
	return (0);
}
