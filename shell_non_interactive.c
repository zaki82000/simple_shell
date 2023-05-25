#include "shell.h"

/**
 * shell_non_interactive - runs shell on non-interactive mode.
 * @file: a pointer to the file.
 */
void shell_non_interactive(FILE *file)
{
	size_t n = 0;

	while (getline(&(info.line), &n, file) != -1)
	{
		(info.count)++;

		if (is_empty(info.line) || info.line[0] == '#')
		{
			free(info.line);
			info.line = NULL;
			continue;
		}

		interpret(info.line);

		free(info.line);
		info.line = NULL;
	}

	free(info.line);
}

/**
 * file_non_interactive - runs shell on non-interactive mode from a file.
 * @name: the file name.
 */
void file_non_interactive(char *name)
{
	FILE *file;
	struct stat st;

	if (stat(name, &st) == -1)
	{
		dprintf(STDERR_FILENO,
			"%s: %d: Can't open %s\n", info.path, info.count, name);
		set_status(127);
		return;
	}

	if (!S_ISREG(st.st_mode))
	{
		set_status(0);
		return;
	}

	if (!(st.st_mode & S_IRUSR))
	{
		dprintf(STDERR_FILENO,
			"%s: %d: Can't open %s\n", info.path, info.count, name);
		set_status(127);
		return;
	}

	file = fopen(name, "r");

	if (file != NULL)
	{
		info.path = name;
		shell_non_interactive(file);
		fclose(file);
	}
}
