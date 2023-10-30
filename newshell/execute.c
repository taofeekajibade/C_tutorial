#include "main.h"
/**
 * execute_command - execute
 * @args: command line arguments
 */
void execute_command(char **args)
{
	int status;

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process*/
		wait(&status);
	}
}
