#include "main.h"

char *read_input()
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1) {
        free(line);
        return NULL;
    }
    return (line);
}
