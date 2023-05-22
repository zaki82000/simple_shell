#include "shell.h"

/**
 * find_build_in - Find a built-in command by name.
 * @name: The name of the command.
 *
 * Return: A function pointer to the built-in command, or NULL if not found.
 */
void (*find_build_in(char *name))(char **av)
{
	int i = 0;
	built_in_t built_ins[] = {
		{"exit", _exit_},
		{"env", _env_},
		{NULL, NULL}
	};

	while (built_ins[i].name != NULL)
	{
		if (_strcmp(built_ins[i].name, name) == 0)
		{
			return (built_ins[i].fun);
		}

		i++;
	}

	return (NULL);
}

/**
 * _exit_ - Exits the shell with status.
 * @av: Array of command arguments.
 */
void _exit_(__attribute__((unused))char **av)
{
	exit(info.status);
}

/**
 * _env_ - Prints all environment variables.
 * @av: Array of command arguments
 */
void _env_(__attribute__((unused)) char **av)
{
	char *newline = "\n";
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, newline, strlen(newline));
	}

	info.status = 0;
}
