#include "main.h"

/* Function to tokenize user input into an array of arguments*/
void tokenize(char *input, int *ac, char ***args)
{
	char* token = strtok(input, " ");
	*ac = 0;
	*args = malloc(sizeof(char*));

	while (token != NULL) {
		*args = realloc(*args, ((*ac) + 1) * sizeof(char*));
		(*args)[(*ac)] = token;
		(*ac)++;
		token = strtok(NULL, " ");
	}

	*args = realloc(*args, ((*ac) + 1) * sizeof(char*));
	(*args)[(*ac)] = NULL;
}