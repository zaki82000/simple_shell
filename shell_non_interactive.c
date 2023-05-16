#include "shell.h"

/**
 * shell_non_interactive - runs shell on non-interactive mode.
 * @info: a pointer to struct that contains all current shell info.
 * @file: a pointer to the file.
 */
void shell_non_interactive(info_t *info, FILE *file)
{
	char *line = NULL;
	size_t n;

	while (getline(&line, &n, file) != -1)
	{
		(info->line_number)++;

		if (line[0] == '\n')
			continue;

		/* parse and execute code will be here */

		/* next line just for testing */
		printf("%s: %d: %s", info->file_name, info->line_number, line);

		free(line);
		line = NULL;
	}

	free(line);
}
