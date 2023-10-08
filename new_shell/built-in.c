#include "main.h"
/**
 * _fexit - A function to exit the shell.
 * @args: Double pointer to an array of strings.
 * Return: args.
 */
void _fexit(char **args)
{
	(void)args;

	exit(EXIT_SUCCESS);
}

/**
 * hanfle_cd - function to change directory
 * @args: arguments
 */
void handle_cd(char **args)
{
	if (args[1] == NULL) 
	{
		perror("usage: cd <directory>");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}

/**
 * abc - command mapping
 */
struct {
	const char *name;
	builtinFunc func;
}
builtin_cmd[] = {
	{"exit", _fexit},
	{"cd", handle_cd},
	{NULL, NULL}
};

void execute_cmd(char **args)
{
	int i;

	for (i = 0; builtin_cmd[i].name != NULL; i++)
	{
		if (strcmp(args[0], builtin_cmd[i].name) == 0)
		{
			builtin_cmd[i].func(args);
			return;
		}
	}
	fork_process(args);
}
