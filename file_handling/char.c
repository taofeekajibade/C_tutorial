#include <stdio.h>
#include <stdlib.h>

/**
 * fopen - creates or opens a file
 * @filename: a pointer to a character for the filename
 * @mode: pointer to a character for file mode
 *
 * Return: a pointer to the object controlling the stream, or NULL on failure	
 *
 * Description - This function is used to create a new file or
 * or open an existing one. It is declared with the stdio.h header.
 * The function has two arguments - the name of the file to be created/opened
 * and the second is the mode in which the file is created or opened.
 *
 * The syntax is: FILE *fopen(const char * filename, const char * mode);
 */
int main(void)
{
	FILE *fp = NULL;
	int i;

	fp = fopen("alphabets.txt", "w");
	if (fp == NULL)
	{
		printf("Failed to create file...\n");
		exit(1);
	}
	
	for (i = 'A'; i <= 'Z'; i++)
	{
		fputc(i, fp);
	}
	fclose(fp);
	printf("Letters A - Z written to the file.\n");
	return (0);
}
