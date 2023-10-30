#include "main.h"
/**
 * init_shell - prompt function
 *
 */
void init_shell()
{
	int interactive = 1;

	if (!isatty(STDIN_FILENO)) 
	{
		interactive = 0;
	}
	if (interactive)
	{
		write(STDOUT_FILENO, "Shell$ ", 7);
	}
}
