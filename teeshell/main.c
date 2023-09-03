#include "main.h"

int main(void)
{
	char *usercmd = NULL;
	size_t buffer = 0;

	print_string("Enter command");
	getline(&usercmd, &buffer, stdin);

	free(usercmd);

	return (0);
}
