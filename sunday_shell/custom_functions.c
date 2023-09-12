#include "main.h"

/* print string */
void print_f(const char *str)
{
	int i;

    for (i = 0; str[i] != '\0'; i++)
	{
        write(STDOUT_FILENO, &str[i], 1);
    }
}

/* string lenght*/
size_t str_len(const char *str)
{
    size_t len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    return (len);
}

/* string duplicate */
char str_dup(const char *str)
{
    size_t len = 0, i;
    char *duplicate;

    if (str == NULL)
    {
        return (-1);
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
    return (*duplicate);
}

/* string compare */
int str_cmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str1++;
	}
	return (*str1 - *str1);
}