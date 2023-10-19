#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>

extern char **environ;
void exit_check(int status, char *dir);
void exit_check(int status, char *dir);


#endif
