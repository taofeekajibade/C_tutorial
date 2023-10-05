#include "main.h"

/* main - main function
 * @ac: argument count
 * @argv: argument vectors
 * Return: Always 0
 */

int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		loop_shell();
	}
	exit(EXIT_SUCCESS);
}
