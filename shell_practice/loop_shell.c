#include "main.h"

void loop_shell(void)
{
    char *userinput;
    char **argv;
    int status;

    signal(SIGINT, handle_sigint);

    do 
    {
        display_prompt();
        userinput = read_line();
        argv = split_token(userinput);
        status = execute_cmd(argv);

        free(userinput);
        free(argv);
    }
    while (status);
}