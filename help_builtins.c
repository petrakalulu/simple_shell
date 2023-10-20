#include "shell.h"

void display_help_text(char *msg);
void display_env_help(void);
void display_setenv_help(void);
void display_unsetenv_help(void);

/**
 * display_help_text - Prints help messages.
 * @msg: Message to be printed.
 */
void display_help_text(char *msg)
{
write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_env_help - Displays info builtin command 'env'.
 */
void display_env_help(void)
{
char *msg = ("env: env\n\tPrints the current environment.\n");
display_help_text(msg);
}

/**
 * display_setenv_help - Displays info on builtin command 'setenv'.
 */
void display_setenv_help(void)
{
char *msg = "setenv: setenv [VARIABLE] [VALUE]\n"
"\tInitializes a new environment, or modifies an existing one.\n\n"
"\tUpon failure, prints a message to stderr.\n";
display_help_text(msg);
}

/**
 * display_unsetenv_help - Displays info on builtin command 'unsetenv'.
 */
void display_unsetenv_help(void)
{
char *msg = "unsetenv: unsetenv [VARIABLE]\n"
"\tRemoves an environmental variable.\n\n"
"\tUpon failure, prints a message to stderr.\n";
display_help_text(msg);
}

