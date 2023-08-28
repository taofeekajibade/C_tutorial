#include <stdio.h>
#include <string.h>
	
int main(void)
{
	char name[100];
	int len;

	printf("Enter your name here: ");
	fgets(name, sizeof(name), stdin );

	name[strcspn(name, "\n")] = '\0';
	len = strlen(name);
	printf("Welcome, %s\n", name);
	printf("The length of the name is: %d\n", len);

	return (0);
}
