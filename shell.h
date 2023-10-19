#ifndef _SHELL_H_
#define _SHELL_H_

/*
 * File: shell.h
 * Auth: Marggie Kalulu
 */

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Builtins */
int (*retrieve_builtin(char *command))(char **args, char **front);
int exit_shell(char **args, char **front);
int execute_env(char **args, char __attribute__((__unused__)) **front);
int execute_setenv(char **args, char __attribute__((__unused__)) **front);
int execute_unsetenv(char **args, char __attribute__((__unused__)) **front);
int change_dir(char **args, char __attribute__((__unused__)) **front);
int execute_alias(char **args, char __attribute__((__unused__)) **front);
int display_help(char **args, char __attribute__((__unused__)) **front);






















#endif
