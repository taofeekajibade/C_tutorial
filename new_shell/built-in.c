#include "main.h"
/**
 * _fexit - A function to exit the shell.
 * @args: Double pointer to an array of strings.
 */
void _fexit(char **args)
{
	int i, status;

    if (args[1] != NULL)
    {
        for (i = 0; args[1][i]; i++)
        {
            if (!isdigit(args[1][i]))
            {
                write(2, INVALID_EXIT, sizeof(INVALID_EXIT) - 1);
                exit(EXIT_FAILURE);
            }
        }
        status = atoi(args[1]);

        if (status < 0 || status > 255)
        {
            write(2, OUT_OF_RANGE, sizeof(OUT_OF_RANGE) - 1);
            exit(EXIT_FAILURE);
        }
        exit(status);
    }
    else
    {
        exit(EXIT_SUCCESS);
    }
}

/**
 * handle_cd - function to change directory
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

/* struct to represent a builtin command */
typedef struct {
	char *cmd;
	void (*func)(char **args);
}builtin_map;

void execute_cmd(char **args)
{
	int i;

	builtin_map cmds[] = {
	{"exit", _fexit},
	{"cd", handle_cd},
	{NULL, NULL}
	};

	if (args[0] == NULL)
	{
		return;
	}
	for (i = 0; cmds[i].cmd != NULL; i++)
	{
		if (strcmp(args[0], cmds[i].cmd) == 0)
		{
			cmds[i].func(args);
			return;
		}
	}
	fork_process(args);
}