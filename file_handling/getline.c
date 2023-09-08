#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t bufsize = 0;
	char *usercmd = NULL;

	printf("Enter your text here...\n");
	getline(&usercmd, &bufsize, stdin);
	printf("The command is: %s buffer size is %ld", usercmd, bufsize);

	free(usercmd);

	return (0);
}
