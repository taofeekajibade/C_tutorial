#include "main.h"

size_t str_len(const char *str)
{
    size_t len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    return (len);
}

char str_dup(const char *str)
{
    size_t len = 0, i;
    char *duplicate;

    if (str == NULL)
    {
        return (NULL);
    }

    
    while (str[len] != '\0')
    {
        len++;
    }
    duplicate = malloc(sizeof(char) * (len + 1));
    if (duplicate == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i <= len; i++)
    {
        duplicate[i] = str[i];
    }
    return (duplicate);
}