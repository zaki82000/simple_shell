#include "shell.h"

/**
 * interpret - interprets the line.
 * @line: a pointer to the line.
 */
void interpret(char *line)
{
	void (*built_in)(char **av);

	info.cmd = parse(line);

	built_in = find_build_in((info.cmd)->path);

	if (built_in != NULL)
	{
		built_in((info.cmd)->av);
	}
	else
	{
		exec(info.cmd);
		free((info.cmd)->path);
	}

	free((info.cmd)->av);
	free(info.cmd);
}
