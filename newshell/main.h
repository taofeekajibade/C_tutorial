#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


void init_shell(void);
char *read_input(void);
char **parse_input(char *line);
void execute_command(char **args);



#endif
