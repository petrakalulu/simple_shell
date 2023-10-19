#include "shell.h"

/**
 * change_directory - Changes the current working directory.
 * @dir: Target directory to change to.
 *
 * This function changes the current working directory to @dir, and manages
 * environment variables accordingly.
 */
void set_current_directory(char *dir)
{
char *new_pwd, *cwd;

/* If no directory is specified, switch to the home directory. */
if (dir[0] == '\0')
{dir = getenv("HOME");
}
/* If '-' is specified, switch to the previous directory. */
else if (strcmp(dir, "-") == 0)
{
dir = getenv("OLDPWD");
}

/* Allocate memory for the current working directory. */
cwd = malloc(sizeof(char) * PATH_MAX);
/* Get the current working directory. */
getcwd(cwd, PATH_MAX);
/* Set the OLDPWD environment variable. */
setenv("OLDPWD", cwd, 1);
/* Free the allocated memory. */
free(cwd);

/* Try changing the directory. */
if (chdir(dir) != 0)
{
perror("cd");
}

/* Allocate memory for the new working directory. */
new_pwd = malloc(sizeof(char) * PATH_MAX);
/* Get the new current working directory. */
getcwd(new_pwd, PATH_MAX);
/* Set the PWD environment variable. */
setenv("PWD", new_pwd, 1);
/* Free the allocated memory. */
free(new_pwd);
}

