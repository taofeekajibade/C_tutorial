#include "main.h"
/**
 * handle_sigint - handles ctrl + C
 * @sig: parameter
 */
void handle_sigint(int sig __attribute__ ((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}