#include "main.h"

void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
