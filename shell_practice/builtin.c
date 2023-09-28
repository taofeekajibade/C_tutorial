#include "main.h"

/* change directory 
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
}*/

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

/**
 * handle_cd - changes directory
 * @path: working directory path
 */
int handle_cd(char **argv)
{
	char *current_dir = getcwd(NULL, 0);
    char *home_dir;

	if (argv[1] == NULL || strcmp(argv[1], "") == 0)
	{
		home_dir = (getenv("HOME"));
        if (home_dir == NULL)
        {
            write(2, "hsh: could not access the home directory\n", 41);
        }
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		argv[1] = getenv("OLDPWD");
	}
	if (current_dir == NULL)
	{
		perror("hsh");
		return (1);
	}
	if (chdir(argv[1]) == -1)
	{
		perror("hsh");
		free(current_dir);
		return (1);
	}
	if (setenv("PWD", getcwd(NULL, 0), 1) == -1)
	{
		perror("setenv");
	}
	if (setenv("OLDPWD", current_dir, 1) == -1)
	{
		perror("setenv");
	}

	free(current_dir);
    return (1);
}