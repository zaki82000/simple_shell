#include "shell.h"

/**
 * shell_non_interactive - runs shell on non-interactive mode.
 * @file: a pointer to the file.
 */
void shell_non_interactive(FILE *file)
{
	char *line = NULL;
	size_t n = 0;

	while (getline(&line, &n, file) != -1)
	{
		(info.count)++;

		if (is_empty(line) || line[0] == '#')
		{
			free(line);
			line = NULL;
			continue;
		}

		interpret(line);

		free(line);
		line = NULL;
	}

	free(line);
}
