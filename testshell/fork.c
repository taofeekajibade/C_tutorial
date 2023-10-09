#include "main.h"

/* Function to execute a command*/
void executeCommand(int ac, char **args, char **env)
{
	int status;
	pid_t pid;
	(void)ac;

	/* Create a child process*/
	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} 
	else if (pid == 0)
	{
		/* In the child process*/
		/* Execute the command with the specified environment*/
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* In the parent process, wait for the child to complete*/
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			WEXITSTATUS(status);
		}
	}
}
