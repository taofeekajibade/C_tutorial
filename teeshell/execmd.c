#include "main.h"

void execmd(char **argv)
{
    char *cmd = NULL;

    if (argv)
	{
        cmd = argv[0]; /*get the command */
        /* executes the command */
        if (execve(cmd, argv, NULL) == -1)
		{
            perror("Error:");
        }
    }

}
