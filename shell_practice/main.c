#include "main.h"

/* main - main function
 * @ac: argument count
 * @argv: argument vectors
 * Return: Always 0
 */

int main(int ac __attribute__((unused)), char **argv)
{
	if (isatty(STDIN_FILENO))
	{
		loop_shell(argv);
	}
	exit(EXIT_SUCCESS);
}
