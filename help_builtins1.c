#include "shell.h"

void display_help_message(char *msgs[], int size);

/**
 * help_all - Displays all possible builtin shellby commands.
 */
void help_all(void)
{
char *msgs[] = {
"Shellby\nThese shell commands are defined internally.\n",
"Type 'help' to see this list.\nType 'help name' to find out more about the function 'name'.\n\n",
"  alias     \talias [NAME[='VALUE'] ...]\n  cd    \tcd [DIRECTORY]\n",
"  exit      \texit [STATUS]\n  env       \tenv\n",
"  setenv    \tsetenv [VARIABLE] [VALUE]\n  unsetenv\tunsetenv [VARIABLE]\n"
};

display_help_message(msgs, sizeof(msgs) / sizeof(msgs[0]));
}

/**
 * help_alias - Displays information on the shellby builtin command 'alias'.
 */
void help_alias(void)
{
char *msgs[] = {
"alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n",
"\n\talias: Prints a list of all aliases, one per line, in the format NAME='VALUE'.\n",
"\talias NAME='VALUE' [...]: Defines an alias for each NAME whose VALUE is given.\n"
};

display_help_message(msgs, sizeof(msgs) / sizeof(msgs[0]));
}

/**
 * help_cd - Displays information on the shellby builtin command 'cd'.
 */
void help_cd(void)
{
char *msgs[] = {
"cd: cd [DIRECTORY]\n\tChanges the current directory of the process to DIRECTORY.\n",
"\tIf no argument is given, the command is interpreted as cd $HOME.\n",
"\tThe environment variables PWD and OLDPWD are updated after a change of directory.\n"
};

display_help_message(msgs, sizeof(msgs) / sizeof(msgs[0]));
}

/**
 * help_exit - Displays information on the shellby builtin command 'exit'.
 */
void help_exit(void)
{
char *msgs[] = {
"exit: exit [STATUS]\n\tExits the shell.\n",
"\tThe STATUS argument is the integer used to exit the shell.\n"
};

display_help_message(msgs, sizeof(msgs) / sizeof(msgs[0]));
}

/**
 * help_help - Displays information on the shellby builtin command 'help'.
 */
void help_help(void)
{
char *msgs[] = {
"help: help\n\tSee all possible Shellby builtin commands.\n",
"\n\thelp [BUILTIN NAME]\n\tSee specific information on each builtin command.\n"
};

display_help_message(msgs, sizeof(msgs) / sizeof(msgs[0]));
}

/**
 * display_help_message - Utility function to display messages.
 * @msgs: An array of message strings.
 * @size: Number of strings in the msgs array.
 */
void display_help_message(char *msgs[], int size)
{
for (int i = 0; i < size; i++)
{
write(STDOUT_FILENO, msgs[i], _strlen(msgs[i]));
}
}

