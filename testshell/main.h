#ifndef _MAIN_H
#define _MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void executeCommand(int ac, char **args, char **env);
char *readInput(void);
void tokenize(char *input, int *ac, char ***args);
void handle_signal(int sig);
void _freedptr(char **args);


#endif