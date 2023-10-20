#include "shell.h"

int display_env_var(char **args);
int modify_env_var(char **args);
int rm_env_var(char **args);

/**
 * display_env_var - display current environment variables.
 * @args: Arguments passed (unused).
 *
 * Return: 0 on success, -1 if an error occurs.
 */
int display_env_var(char **args)
{
int m;
char newline = '\n';

if (!environ)
return (-1);

for (m = 0; environ[m]; m++)
{
write(STDOUT_FILENO, environ[m], _strlen(environ[m]));
write(STDOUT_FILENO, &newline, 1);
}

(void)args;
/* Args is unused, this is to bypass compiler warnings. */
return (0);
}

/**
 * modify_env_var - Sets new env var or modifies an existing one.
 * @args: Array containing the environment variable and value.
 *
 * Return: 0 on success, -1 if an error occurs.
 */
int modify_env_var(char **args)
{
char **env_var, *new_var;
int m, size;

if (!args[0] || !args[1])
return (create_error(args, -1));

new_var = create_new_var(args);
/* A new function to handle new var creation. */
if (!new_var)
return (create_error(args, -1));

env_var = _getenv(args[0]);
return (modify_env_var(args, env_var, new_var));
}

/**
 * rm_env_var - Removes an environment variable.
 * @args: Array containing the environment variable to be removed.
 *
 * Return: 0 on success, -1 if an error occurs.
 */
int rm_env_var(char **args)
{
char **env_var, **new_environ;
int m, n, size;

if (!args[0])
return (create_error(args, -1));

env_var = _getenv(args[0]);
if (!env_var)
return (0);
size = get_env_size();
/* A new function to get the environment size. */
new_environ = create_new_environ(size);
/* New function to create new environment. */
if (!new_environ)
return (create_error(args, -1));

return (update_environment(env_var, new_environ, size));
/* Update environment function. */
}

