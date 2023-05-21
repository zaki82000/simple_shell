#include "shell.h"

/**
 * find_build_in - Find a built-in command by name
 * @name: The name of the command
 *
 * Return: A function pointer to the built-in command, or NULL if not found
 */
void (*find_build_in(char *name))(info_t *info, char **av)
{
	int i = 0;
	built_in_t built_in[] = { 
		{"exit", _exit_},
		{"env", _env_},
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
 */
void _exit_(info_t *info, char **av)
{
	exit(info->status);
}

/**
 * env - Built-in command: env
 * @info: Pointer to the info_t structure
 * @av: Array of command arguments
 */
void _env_(info_t *info, char **av) 
{
	char *newline = "\n";
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, newline, strlen(newline));
	}

	info->status = 0;
}
