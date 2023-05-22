#include "shell.h"

/**
* envdup - duplicates an enviornment variable.
* @name: the name of the enviornment variable.
*
* Return: a pointer to duplicated variable.
*/
char *envdup(char *name)
{
	char *env, *dup;

	env = getenv(name);

	if (env == NULL)
		return (NULL);

	dup = _strdup(env);

	if (dup == NULL)
		return (NULL);

	return (dup);
}
