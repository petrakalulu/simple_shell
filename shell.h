#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <limits.h>


extern char **environ;
void set_current_directory(char *dir);
void exit_check(int status, char *dir);


#endif
