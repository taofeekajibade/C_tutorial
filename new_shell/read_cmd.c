#include "main.h"
/**
 * read_line - read user input
 */
char *read_line(void)
{
	char *user_input = NULL;
	size_t bufsize = 0;

	if (getline(&user_input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	return (user_input);
}
