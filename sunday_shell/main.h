#ifndef _MAIN_H
#define _MAIN_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* PROTOTYPES */
void execute_file(char **argv);
size_t str_len(const char *str);
char *get_path(char *usercmd);
char *getenv(const char *file_path);


#endif