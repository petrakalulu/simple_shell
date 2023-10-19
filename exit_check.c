#include "shell.h"

/**
 * exit_check - Checks the exit status of a command.
 * @status: The exit status to be checked.
 *
 * This function checks whether a command has exited normally and
 * whether its exit status is non-zero, printing an error message if so.
 */
void exit_check(int status, char *dir)
{
/* Check if the command exited normally. */
if (WIFEXITED(status))
{
/* Get the exit status of the command. */
int exit_status = WEXITSTATUS(status);

/* If the exit status is non-zero, print an error message. */
if (exit_status != 0)
{
printf("Error: command exited with status %d\n", exit_status);
}
}
}

