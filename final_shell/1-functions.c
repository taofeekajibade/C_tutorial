#include "main.h"

void print_prompt(void)
{
    print_f("#cisfun$ ");
}

/* signal */
void handle_sigint(int sig)
{
    write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/* user input */
char *get_user_input(size_t *bufsize)
{
    char *user_input = NULL;
    ssize_t char_read;

    char_read = getline(&user_input, bufsize, stdin);
    if (char_read == -1)
    {
        if (feof(stdin))
        {
            print_f("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    return user_input;
}

/* tokenize user input */
void tokenize_input(char *user_input, int *ac, char **args, char *delim)
{
    char *token = strtok(user_input, delim);

    while (token != NULL && *ac < MAX_COUNT)
    {
        args[(*ac)++] = token;
        token = strtok(NULL, delim);
    }
    args[*ac] = NULL;
}

/* execute command */
void execute_command(int ac, char **args, char *envp[])
{
    pid_t pid;
    int status;

    if (ac > 0)
    {
        if (strcmp(args[0], "exit") == 0)
        {
            exit(EXIT_SUCCESS);
        }
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (strcmp(args[0], "cd") == 0)
        {
            if (args[1] == NULL)
            {
                print_f("Usage: cd <directory");
            }
            else
            {
                if (chdir(args[1]) != 0)
                {
                    perror("cd");
                }
            }
        }
        if (pid == 0)
        {
            if (execve(args[0], args, envp) == -1)
            {
                print_f("command not found\n");
                exit(EXIT_FAILURE);
            };
        }
        else
        {
            wait(&status);
            if (WIFEXITED(status))
            {
                print_f("Child process exited with status.\n");
            }
        }
    }
}