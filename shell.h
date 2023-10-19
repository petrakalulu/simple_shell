#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>

#define AND_OPERATOR 1
#define OR_OPERATOR 2
#define MAX_ARGS 50

extern char **environ;
void exit_check(int status, char *dir);
void exit_check(int status, char *dir);
char *split_string(char *str, const char *delim)
int process_and_execute_command(char **args)

#endif
