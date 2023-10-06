#include "main.h"
/**
 * loop_shell - loops through the functions
 */
void loop_shell(char **argv)
{
	char *userinput;
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
