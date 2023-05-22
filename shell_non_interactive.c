#include "shell.h"

/**
 * shell_non_interactive - runs shell on non-interactive mode.
 * @file: a pointer to the file.
 */
void shell_non_interactive(FILE *file)
{
	char *line;
	size_t n;

	while (getline(&line, &n, file) != -1)
	{
		(info.line_number)++;

		if (is_empty(line))
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
