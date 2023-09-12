#include "main.h"
/* gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh */
int main(int ac, char **argv)
{
    char *prompt = "(new_shell)>>> ";
    char *usercmd = NULL;
    size_t bufsize = 0;
    ssize_t char_read = 0;
    char *usercmd_cpy = NULL;
    char *delim = " \n";
    char *token = NULL;
    int token_sum = 0, i;

    (void)ac;

    while (1)
    {
        write(STDOUT_FILENO, prompt, str_len(prompt));
       
        char_read = getline(&usercmd, &bufsize, stdin);
        if (char_read == -1)
        {
            printf("Goodbye...\n");
            return (-1);
        }
        /* create a variable to hold user inputs and allocate memory to it */
        usercmd_cpy = malloc(sizeof(char)* char_read);
        if (usercmd_cpy == NULL)
        {
            perror("malloc");
            return (-1);
        }
        /* copy user input into the new variable */
        strcpy(usercmd_cpy, usercmd);

        /* tokenize user input and save it in a variable token */
        token = strtok(usercmd, delim);
        while (token != NULL)
        {
            token_sum++; 
            token = strtok(NULL, delim);
        }
        token_sum++; /* total number of token */

        argv = malloc(sizeof(char *) * token_sum);
        token = strtok(usercmd_cpy, delim); /* tokenize a copy of user input */
        while (token != NULL)
        {
            argv[i] = strdup(token);
            i++;
            token = strtok(NULL, delim);
        }
        argv[i] = NULL; /* set the last sting to null terminator */


        /* printf("%s\n", usercmd); */

        execute_file(argv);
    }
    free(usercmd);
    free(usercmd_cpy);

    return (0);
}