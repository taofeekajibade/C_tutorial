#include <stdio.h>
#include <stdlib.h>

/* Declare the external variable environ */
extern char** environ;

int main()
{
	char **env;

    for (env = environ; *env != NULL; env++)
	{
        printf("%s\n", *env);
    }

    return 0;
}

