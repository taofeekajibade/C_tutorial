#include "main.h"
/**
 * fork_process - function to process a command
 * @ac: argument count
 * @args: argument vectors
 * @env: environment variables
 */
void fork_process(int ac, char **args, char **env)
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
	/* begin the child process to execute the command */
	else if (pid == 0)
	{
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
			WEXITSTATUS(status);
	}
}

/**
 * executeCommand - executes user commands
 * @ac: argument count
 * @args: argument vectors
 * @env: environment variables
 */
void executeCommand(int ac, char **args, char **env)
{
	if (args[0] == NULL)
		return;

	if (strcmp(args[0], "exit") == 0)
		_fexit(args);
	else
		fork_process(ac, args, env);
}
