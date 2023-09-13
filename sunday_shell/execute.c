#include "main.h"

void execute_file(char **argv)
{
    char *usercmd = NULL;
    char *usercmd_path = NULL;
   
    if (argv)
    {
        usercmd = argv[0];
        usercmd_path = get_path(usercmd);
    
        if (execve(usercmd_path, argv, NULL) == -1)
        {
            perror("execve");
        }
    }
}