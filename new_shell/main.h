#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>


#define MAX_INPUT 255
#define DELIM " \t"
#define BUFFER_SIZE 64

#define MANY_ARGUMENTS "Too many arguments\n"
#define NUMERIC_REQUIRED "Numeric value required\n"
#define INVALID_EXIT "Invalid exit status value\n"
#define OUT_OF_RANGE "Exit status out of range (0-255)\n"

/* custom functions */
void _freedptr(char **args);
void handle_exit(char **args);
void handle_cd(char **args);
char **_tokenize(char ***args, char *input);
char *read_input(void);
void handle_signal(int sig);
int fork_process(char **args, char **env);
void execute_cmd(char **args, char **env);
char **split_token(char *user_input);

#endif
