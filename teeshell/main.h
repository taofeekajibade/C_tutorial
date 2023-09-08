#ifndef _MAIN_H
#define _MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_string(char *str);
void execmd(char **argv);
char *locate_path(char *cmd);


#endif
