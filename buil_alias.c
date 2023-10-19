#include "shell.h"

int execute_alias_command(char **args, char __attribute__((__unused__)) **front);
void create_alias(char *var_name, char *value);
void display_alias(alias_t *alias);

/**
 * execute_alias - Builtin command that either prints all aliases, specific
 * aliases, or sets an alias.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int execute_alias_command(char **args, char __attribute__((__unused__)) **front)
{
alias_t *temp = aliases;
int m, ret = 0;
char *value;

if (!args[0])
{
while (temp)
{
print_alias(temp);
temp = temp->next;
}
return (ret);
}
for (m = 0; args[m]; m++)
{
temp = aliases;
value = _strchr(args[m], '=');
if (!value)
{
while (temp)
{
if (_strcmp(args[m], temp->name) == 0)
{
print_alias(temp);
break;
}
temp = temp->next;
}
if (!temp)
ret = create_error(args + m, 1);
}
else
set_alias(args[m], value);
}
return (ret);
}

/**
 * create_alias - Will either set an existing alias 'name' with a new value,
 * 'value' or creates a new alias with 'name' and 'value'.
 * @var_name: Name of the alias.
 * @value: Value of the alias. First character is a '='.
 */
void create_alias(char *var_name, char *value)
{
alias_t *temp = aliases;
int len, l, n;
char *new_value;

*value = '\0';
value++;
len = _strlen(value) - _strspn(value, "'\"");
new_value = malloc(sizeof(char) * (len + 1));
if (!new_value)
return;
for (l = 0, n = 0; value[l]; l++)
{
if (value[l] != '\'' && value[l] != '"')
new_value[n++] = value[l];
}
new_value[n] = '\0';
while (temp)
{
if (_strcmp(var_name, temp->name) == 0)
{
free(temp->value);
temp->value = new_value;
break;
}
temp = temp->next;
}
if (!temp)
add_alias_end(&aliases, var_name, new_value);
}

/**
 * display_alias - Prints the alias in the format name='value'.
 * @alias: Points an alias.
 */
void display_alias(alias_t *alias)
{
char *alias_string;
int len = _strlen(alias->name) + _strlen(alias->value) + 4;

alias_string = malloc(sizeof(char) * (len + 1));
if (!alias_string)
return;
_strcpy(alias_string, alias->name);
_strcat(alias_string, "='");
_strcat(alias_string, alias->value);
_strcat(alias_string, "'\n");

write(STDOUT_FILENO, alias_string, len);
free(alias_string);
}
/**
 * display_aliases - Goes through the arguments and replace any matching alias
 * with their value.
 * @args: 2D pointer to the arguments.
 *
 * Return: 2D pointer to the arguments.
 */
char **display_aliases(char **args)
{
alias_t *temp;
int m;
char *new_value;

if (_strcmp(args[0], "alias") == 0)
return (args);
for (m = 0; args[m]; m++)
{
temp = aliases;
while (temp)
{
if (_strcmp(args[i], temp->name) == 0)
{
new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
if (!new_value)
{
free_args(args, args);
return (NULL);
}
_strcpy(new_value, temp->value);
free(args[m]);
args[m] = new_value;
m--;
break;
}
temp = temp->next;
}
}

return (args);
}
