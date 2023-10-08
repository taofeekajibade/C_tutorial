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
    char *token = strtok(input, DELIM);

    while (token)
    {
        /**
		 * Check if allocated memory is sufficient for tokenization,
		 * and reallocate if necessary.
		 */
        if (i >= token_size)
        {
            token_size *= 2;
            *args = realloc(*args, token_size * sizeof(char *));
        }

        (*args)[i] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy((*args)[i], token);
        i++;
        token = strtok(NULL, " ");
    }

    (*args)[i] = NULL;

    return *args;
}
