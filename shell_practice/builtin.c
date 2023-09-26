#include "main.h"

/* change directory */
int handle_cd(char **argv)
{
    if (argv[1] == NULL)
    {
        write(STDERR_FILENO, "hsh: expected cd <directory>\n", 29);
    }
    else
    {
        if (chdir(argv[1]) == -1)
        {
            perror("hsh");
        }
    }
    return (1);
}

/* exit function */
int handle_exit(char **argv)
{
    exit(EXIT_SUCCESS);
}

/* shell help function 
int handle_help(char **argv)
{
    int i;
    char *builtin_code;

    write(STDOUT_FILENO, "This is a simple shell built by Taofeek Ajibade.\nType the program names and arguments, and hit enter.\nThe builtin functions are as follows:\n", 141);
    for (i = 0; i < builtin_select(); i++)
    {
        printf(" %s\n", builtin_code[i]);
    }
    write(STDOUT_FILENO, "Use the 'man' command to get details about other programs.\n", 59);
    return (1);
} */