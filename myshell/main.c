#include "main.h"

int main(int argc, char *argv[])
{
	char *user_input = NULL;
	size_t bufsize = 0;
	char *token = NULL;
	char *usercmd = NULL;
	char *arguments = NULL;
	char *delim = " ";
	pid_t pid;
	int status, exit_status;
	char *cmd_args[] = {usercmd, arguments, NULL};

	while (1)
	{
		print_f("(weshell) $ ");
		if (getline(&user_input, &bufsize, stdin) == -1)
		{
			perror("getline");
			break;
		}
		token = strtok(user_input, delim);
		if (token != NULL)
		{
			usercmd = token;
			token = strtok(NULL, delim);
			arguments = token;
		}
		if (usercmd != NULL)
		{
			if (str_cmp(usercmd, "cd") == 0)
			{
				if (arguments != NULL)
				{
					perror("chdir");
				}
			}
			else
			{
				if (chdir(getenv("HOME")) != 0)
				{
					perror("chdir");
				}
			}
			continue;
		}
		if (str_cmp(usercmd, "exit") == 0)
		{
			free(user_input);
			user_input = NULL;
			break;
		}
		if (str_cmp(usercmd, "echo") == 0)
		{
			if (arguments != NULL)
			{
				print_f(arguments);
				print_f("\n");
			}
			continue;
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				execve(usercmd, cmd_args, NULL);  
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, &status, 0);
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
		free(user_input);
		user_input = NULL;
	}
	return (0);
}
