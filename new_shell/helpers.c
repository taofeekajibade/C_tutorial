#include "main.h"

/**
 * _tokenize - A function to tokenize a string.
 *
 * @args: Double pointer to an array of strings.
 * @token: String tokens.
 * @token_size: Allocated size per token.
 * @user_input: Input from user.
 *
 * Return: args.
 */
char **_tokenize(char ***args, char *input)
{
    size_t i = 0, token_size = MAX_INPUT;
    char **tokens = malloc(token_size * sizeof(char *));
    char *token = strtok(input, DELIM);

    if (!tokens)
    {
        perror("hsh: allocation error");
        exit(EXIT_FAILURE);
    }

    while (token)
    {
        tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
        if (!tokens[i])
        {
            perror("hsh: allocation error");
            exit(EXIT_FAILURE);
        }
        strcpy(tokens[i], token);
        i++;

        if (i >= token_size)
        {
            token_size *= 2;
            tokens = realloc(tokens, token_size * sizeof(char *));
            if (!tokens)
            {
                perror("hsh: allocation error");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIM);
    }

    tokens[i] = NULL;
    /* Update the pointer passed as an argument */
    *args = tokens;

    return tokens;
}