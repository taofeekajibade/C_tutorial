#include "main.h"

int main(int argc, char *argv[])
{
	char *usercmd = NULL;
	size_t bufsize = 0;
	char *token = NULL;
	char **args = NULL;
	char *delim = " \n";
	pid_t pid;
	int i = 0, j = 0, status, exit_status;

	while (1)
	{
		i = 0;
		print_f("(weshell) $ ");
		if (getline(&usercmd, &bufsize, stdin) == -1)
		{
			perror("getline");
			free(usercmd);
			break;
		}
		args = malloc(sizeof(char*));
		token = strtok(usercmd, delim);
		while (token != NULL)
		{
			args[i] = strdup(token);
			token = strtok(NULL, delim);
			i++;
			/*args = realloc(args, (i+1)*sizeof(char*)); */
		}
		/* args[i] = NULL; */

		while (args[i] != NULL)
		{
			
			if (str_cmp(args[0], "cd") == 0)
			{
				if(args[1] != NULL)
				{
					chdir(args[1]);
				}
				else
				{
					chdir(getenv("HOME"));
				}
				continue;
			}

			else if (str_cmp(args[0], "exit") == 0)
			{
				free(usercmd);
				break;
			}

			else if (str_cmp(args[0], "echo") == 0)
			{
				for(j=1; args[j] != NULL; j++)
				{
				print_f(args[j]);
				print_f(" ");
				}
				print_f("\n");
				continue;
			}

			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}

			else if (pid == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
				{
					exit_status = WEXITSTATUS(status);
					print_f("Child process exited with status: ");
					print_f(exit_status == 0? "Success" : "Error");
					print_f("\n");
				}
				else
				{
					print_f("Child process did not exit normally \n");
				}
			}
			for (j = 0; j < i; j++)
			{
				free(args[j]);
			}
		}
		free(args);
		free(usercmd);
		usercmd = NULL;
	}
	return (0);
}
