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
