#include "shell.h"
#include "string_utils.c"

/**
 * find_build_in - Find a built-in command by name
 * @name: The name of the command
 *
 * Return: A function pointer to the built-in command, or NULL if not found
 */
int (*find_build_in(char *name))(info_t *info, char **av)
{
	int i = 0;
	built_in_t built_in[] = { 
		{"exit", exit_shell},
		{"env", env},
		{NULL, NULL}
	};

	while (built_in[i].name != NULL)
	{
		if (_strcmp(built_in[i].name, name) == 0)
		{
			return built_in[i].fun;
		}
		i++;
	}

	return NULL;
}

/**
 * exit_shell - Built-in command: exit
 * @info: Pointer to the info_t structure
 * @av: Array of command arguments
 *
 * Return: None
 */
int exit_shell(info_t *info, char **av)
{
	exit(0);
}

/**
 * env - Built-in command: env
 * @info: Pointer to the info_t structure
 * @av: Array of command arguments
 *
 * Return: None
 */
int env(info_t *info, char **av) 
{
	extern char **environ;
	char *newline = "\n";
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, newline, strlen(newline));
	}
}
