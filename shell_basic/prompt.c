#include <stdio.h>
#include <stdlib.h>

/* Write a program that prints "$ ", wait for the user to enter a command,
 * prints it on the next line.*/

int main(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t char_read;

	printf("Enter $ ");

	char_read = getline(&input, &bufsize, stdin);
	if (char_read == -1)
	{
		perror("getline");
		free(input);
		return (-1);
	}
	else
	{
		printf("%s\n", input);
	}
	free (input);

	return (0);
}
