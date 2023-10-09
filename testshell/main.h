#ifndef _MAIN_H
#define _MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>


#define MAX_INPUT 1024
#define DELIM " \n"
#define INVALID_EXIT "Invalid exit value\n"
#define OUT_OF_RANGE "Value out of range 0 - 255\n"

void fork_process(int ac, char **args, char **env);
void executeCommand(int ac, char **args, char **env);
char *readInput(void);
/*void tokenize(char *input, int *ac, char ***args);*/
void handle_signal(int sig);
void _freedptr(char **args);
char **_tokenize( char *input, char ***args);
void _fexit(char **args);


#endif