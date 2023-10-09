#include "main.h"
/**
 * fork_process - start a process
 * @argv: user commands
 * @env: environment variable
 * Return: the exit status of the child process
 */
int fork_process(char **args, char **env)
{
	pid_t pid;
	int status, exit_status;

	/* fork a process and check its pid value */
	pid = fork();

	if (pid < 0)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* the child process */
		if (execve(args[0], args, env) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
		}
	}
	/* return the exit status of the child process */
	return (exit_status);
}