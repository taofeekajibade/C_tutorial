#include <stdio.h>
#include <stdlib.h>
/**
 * main - the main function
 * @ac: argument count
 * @argv: pointers to the pointers to array of strings.
 * Return: 0 on sucess, or -1 on failure.
 *
 * Description - Write a program that prints its name, followed by a new line.
 * If you rename the program, it will print the new name,
 * without having to compile it again.
 * You should not remove the path before the name of the program.
 */

int main(int ac, char *argv[])
{
	printf("%d\n", ac);
	while (ac--)
		printf("%s\n", *argv++);
	exit(EXIT_SUCCESS);
}
