#include "main.h"

/**
 * _freedptr - A function to free a double pointer.
 *
 * @args: Double pointer to an array of strings.
 *
 * Return: Void.
 */

void _freedptr(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}

	if (args)
	{
		free(args);
	}
}
