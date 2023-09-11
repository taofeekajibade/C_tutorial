#include "main.h"

int main(int ac, char **args, char *envp[])
{
    char *user_input = NULL;
    size_t bufsize = 0;
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