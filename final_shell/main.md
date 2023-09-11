#include "main.h"

int main(int ac, char **args, char *envp[])
{
    char *user_input = NULL;
    size_t bufsize = 0;
    ssize_t char_read;
    pid_t pid;
    int status;
    char *token = NULL;
    char *delim = " \n";

    #define MAX_COUNT 10

    while (1)
    {
        print_prompt();
        char_read = getline(&user_input, &bufsize, stdin);
        if (char_read == -1)
        {
            if (feof(stdin))
            {
                print_f("\n");
                break;
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(user_input, delim);
        ac = 0;

        while (token != NULL && ac < MAX_COUNT)
        {
            args[ac++] = token;
            token = strtok(NULL, delim);
        }
        args[ac] = NULL;

        if (ac > 0)
        {
            pid = fork();
            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            if (pid == 0)
            {
                execve(args[0], args, envp);
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(&status);
                if (WIFEXITED(status))
                {
                    print_f("Child process exited with status \n");
                    /*print_f(WIFEXITED(status));*/
                }
            }
        }

    }
    free(user_input);
    free(bufsize);
    return (0);
}