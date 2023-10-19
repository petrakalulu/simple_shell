#include <stdio.h>
#include <string.h>
#include "shell.h"

/**
 * _strtok - Tokenizes a string by breaking it into words.
 * @str: The string to tokenize.
 * @delim: The delimiter used to split the string.
 * Return: A pointer to the next token, or NULL if there are no more tokens.
 */
char *split_string(char *str, const char *delim)
{
char *last_token = NULL;
/* Holds the last token returned by the function. */
char *token;
/* Current token to be returned. */

/* If a string is provided, start tokenizing from the new string. */
if (str)
{
last_token = str;
}

if (!last_token)
{
return (NULL);
/* No more tokens. */
}

token = last_token;

/* Skip delimiters at the beginning of the string. */
while (*token && strchr(delim, *token))
{
token++;
}

if (!*token)
{
last_token = NULL;
return (NULL);
/* Reached the end of the string. */
}

last_token = token + 1;

/* Find the end of the current token. */
while (*last_token && !strchr(delim, *last_token))
{
last_token++;
}
if
(!*last_token)
{
last_token = NULL;
}
else
{
*last_token = '\0';
last_token++;
}
return (token);
/* Return the current token. */
}

