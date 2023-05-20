#include "shell.h"

/**
 * shell_non_interactive - runs shell on non-interactive mode.
 * @info: a pointer to struct that contains all current shell info.
 * @fd: tha file descriptor.
 */
void shell_non_interactive(info_t *info, int fd)
{
	char *line = NULL;

	while ((line = readline(fd)) != NULL)
	{
		(info->line_number)++;

		if (line[0] == '\n')
			continue;

		/* parse and execute code will be here */

		/* next line just for testing */
		printf("%s: %d: %s", info->file_path, info->line_number, line);
		fflush(stdout);

		free(line);
	}
}
