#include "shell.h"

char **copy_environment(void);
void free_environment(void);
char **get_environment_variable(const char *variable_name);

/**
 * copy_environment - Creates a deep copy of the environment variables.
 *
 * Return: Points the copied env var. NULL if an err occurs.
 */
char **copy_environment(void)
{
char **new_environment;
size_t env_size;
int m;

/* Calculate the number of environment variables. */
for (env_size = 0; (environ[env_size]; env_size++));

/* Allocate memory for the new environment variables array. */
new_environment = malloc(sizeof(char *) * (env_size + 1));
if (!new_environment)
return (NULL);

/* Copy each environment variable. */
for 
(m = 0; (environ[m]; m++))
{
new_environment[m] = strdup(environ[m]);
        
/* If allocation fails, clean up and return NULL. */
if (!new_environment[m])
{
while (m >= 0)
free(new_environment[m--]);
free(new_environment);
return (NULL);
}
}
new_environment[m] = NULL;

return (new_environment);
}

/**
 * free_environment - Frees allocated memory for the copied env var.
 */
void free_environment(void)
{
int m;

for (m = 0; environ[m]; m++)
free(environ[m]);
free(environ);
}

/**
 * get_environment_variable - Retrieves the value of an environment variable.
 * @variable_name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the environment variable, or NULL if it does not exist.
 */
char **get_environment_variable(const char *variable_name)
{
int m, name_length;

name_length = strlen(variable_name);

for (m = 0; environ[m]; m++)
{
if (strncmp(variable_name, environ[m], name_length) == 0 && environ[m][name_length] == '=')
return (&environ[m]);
}

return (NULL);
}

