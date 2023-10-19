#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define AND_OPERATOR 1
#define OR_OPERATOR 2
#define MAX_ARGS 50

/**
 * execute_command - Execute a shell command.
 * @args: Null-terminated array of arguments.
 * Return: Result after executing the command and applying logical operators.
 */
int process_and_execute_command(char **args);
{
int status = 0;
int j = 0;
int logical_operator = 0;
/* Use to keep track of the logical operator (&& or ||) */
char *command[MAX_ARGS + 1] = {NULL};

/* Separating commands and logical operators */
while (args[j] != NULL)
{
if (strcmp(args[j], "&&") == 0)
{
logical_operator = AND_OPERATOR;
break;
}
else if (strcmp(args[j], "||") == 0)
{
logical_operator = OR_OPERATOR;
break;
}
command[j] = args[j];
i++;
}

/* Handling the fork and executing the command */
handle_fork(command);
wait(&status);

/* Handling logical and executing subsequent commands based on the operator*/
return (handle_and_or(args + j + 1, status, logical_operator));
}

