#ifndef _MAIN_H
#define _MAIN_H

#define MAX_COUNT 10


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* PROTOTYPES */
void print_f(const char *str);
void print_prompt(void);
char *get_user_input(size_t *bufsize);
void tokenize_input(char *user_input, int *ac, char **args, char *delim);
void execute_file(char **argv);
size_t str_len(const char *str);
char *get_path(char *usercmd);
char *getenv(const char *file_path);
void handle_sigint(int sig);
void execute_command(int ac, char **args, char *envp[]);


#endif