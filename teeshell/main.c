#include "main.h"

int main(void)
{
	char *usercmd = NULL;
	char *token;
	size_t bufsize = 0;

	while (1)
	{
		print_string("(myshell) >>> "); /*prints prompt */
		getline(&usercmd, &bufsize, stdin);
		if (usercmd == NULL)
		{
			perror("Error reading input...");
			return (-1);
		}

		token = strtok(usercmd, " ");
		while (token != NULL)
		{
			print_string(token);
			print_string("\n");
			token = strtok(NULL, " ");
		}
		if (strcmp(token, "exit") == 0) /* handles exit */
		{
			print_string("Goodbye...");
			break;
		}
		if (strcmp(token, "cd") == 0)
		{
			token = strtok(NULL, " \n");
			if (token == NULL)
			{
				print_string("Usage: cd <directory>");
			}
			else
			{
				if(chdir(token) != 0)
				{
					perror("cd");
				}
			}
		}
		else
		{
			print_string(token);
		}
		free(usercmd);
		bufsize = 0;
	}
	return (0);
}
