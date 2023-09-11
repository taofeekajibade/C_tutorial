#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 10

void handle_sigint(int sig)
{
    write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

void print_prompt(void)
{
    printf("#cisfun$ ");
}

char *get_user_input(size_t *bufsize)
{
    char *user_input = NULL;
    ssize_t char_read;

    char_read = getline(&user_input, bufsize, stdin);
    if (char_read == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
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
        else if (strcmp(args[0], "cd") == 0)
        {
            if (args[1] == NULL)
            {
                printf("cd: expected argument\n");
            }
            else
            {
                if (chdir(args[1]) != 0)
                {
                    perror("cd");
                }
            }
            return;
        }
        else if (strcmp(args[0], "echo") == 0 || strcmp(args[0], "ls") == 0 || strcmp(args[0], "history") == 0)
        {
            pid = fork();
            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            if (pid == 0)
            {
                char *path;
                if(strcmp(args[0], "echo") == 0) 
                    path = "/bin/echo";
                else if(strcmp(args[0], "ls") == 0) 
                    path = "/bin/ls";
                else 
                    path = "/usr/bin/history";
                
                execve(path, args, envp);
                perror(args[0]);
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(&status);
                if (WIFEXITED(status))
                {
                    printf("Child process exited with status %d\n", WEXITSTATUS(status));
                }
            }
            return;
        }

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            execve(args[0], args, envp);
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
            if (WIFEXITED(status))
            {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }
}

int main(int ac, char **args, char *envp[])
{
    size_t bufsize = 0;
    char *user_input;
    char *delim = " \n";

    signal(SIGINT, handle_sigint);

    while (1)
    {
        print_prompt();
        user_input = get_user_input(&bufsize);

        tokenize_input(user_input, &ac, args, delim);

        execute_command(ac, args, envp);

        free(user_input);
    }

    return (0);
}