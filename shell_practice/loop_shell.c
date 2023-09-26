#include "main.h"

void loop_shell(void)
{
    char *userinput;
    char **argv;
    int status;

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

int main(int ac, char **argv)
{
    loop_shell();

    exit(EXIT_SUCCESS);
}