#include "main.h"


void execute_command(char **args)
{
	if (execve(args[0], args, NULL) == -1) {
		perror("Error executing command");
	}
}
