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
	char name[50] = {0};

	fp = fopen("firstfile.txt", "w");
	if (fp == NULL)
	{
		printf("Failed to create file...\n");
		exit(1);
	}
	
	for (i = 1; i < 4; i++)
	{
		puts("Enter student name one after the other...\n");
		fgets(name, sizeof(name), stdin);
		fprintf(fp, "%d. Name = %s\n", i, name);
	}
	fclose(fp);
	return (0);
}
