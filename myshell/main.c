#include "main.h"

int main(int argc, char *argv[])
{
	char *usercmd = NULL;
	size_t bufsize = 0;
	char *token = NULL;
	char **args = NULL;
	char *delim = " ";
	pid_t pid;
	int i, status, exit_status;
	char *cmd_args[3];

	while (1)
	{
		print_f("(weshell) $ ");
		if (getline(&usercmd, &bufsize, stdin) == -1)
		{
			perror("getline");
			free(usercmd);
			break;
		}
		token = strtok(usercmd, delim);
		while (token != NULL)
		{
			args[i] = strdup(token);
			token = strtok(NULL, delim);
			i++;
		}
		if (token != NULL)
		{
			if (str_cmp(args[0], "cd") == 0 && args[1] != NULL)
			{
				chdir(args[1]);
			}
			else
			{
				(chdir(getenv("HOME")));
			}
			if (str_cmp(args[0], "exit") == 0)
			{
				free(usercmd);
				usercmd = NULL;
				break;
			}
			else if (str_cmp(args[0], "echo") == 0)
			{
				if (args[i]!= NULL)
				{
					print_f(args[i]);
					print_f("\n");
				}
			}
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				execve(usercmd, args, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
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
		}
		free(usercmd);
		usercmd = NULL;
	}
	return (0);
}
