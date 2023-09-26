#include "main.h"

char **split_token(char *userinput)
{
    int bufsize = BUFFER_SIZE, i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token, **tokens_cpy;

    if (!tokens)
    {
        write(STDERR_FILENO, "hsh: allocation error\n", 22);
        exit(EXIT_FAILURE);
    }
    token = strtok(userinput, DELIM);
    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        if (i >= bufsize)
        {
            bufsize += BUFFER_SIZE;
            tokens_cpy = tokens;
            token = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                free(tokens_cpy);
                write(STDERR_FILENO, "hsh: allocation error\n", 22);
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;
    return (tokens);
}