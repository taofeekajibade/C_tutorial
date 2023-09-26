#include "main.h"

/* Array of builtin commands */
char *builtin_code[] = 
{
    "cd",
    "exit",
};

/* Array of corresponding builtin functions */
int (*builtin_func[])(char **) =
{
    &handle_cd,
    &handle_exit,
    /* &handle_help */
};

int builtin_select(void)
{
    return sizeof(builtin_code) / sizeof(char *);
}

/* execute external commands */
int fork_process(char **argv)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("hsh");
    }
    else
    {
        do 
        {
            waitpid(pid, &status, WUNTRACED);
        }
        while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (1);
}

int execute_cmd(char **argv)
{
    int i;
    if (argv[0] == NULL)
    {
        return (-1);
    }
    for (i = 0; i < builtin_select(); i++)
    {
        if (strcmp(argv[0], builtin_code[i]) == 0)
        {
            return (*builtin_func[i])(argv);
        }
    }
    return (fork_process(argv));
}