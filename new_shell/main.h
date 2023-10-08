#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_INPUT 255
#define DELIM " "

/* function pointer type for command functions*/
typedef void (*builtinFunc)(char **args);

/* custom functions */
void _freedptr(char **args);
void _fexit(char **args);
void handle_cd(char **args);
char **_tokenize(char ***args, char *input);
char *read_line(void);
void handle_signal(int sig);
int fork_process(char **args);
void execute_cmd(char **args);
void loopFunctions(char **args);









#endif
