#include "shell.h"

/**
 * interpret - interprets the line.
 * @line: a pointer to the line.
 */
void interpret(char *line)
{
	command_t *cmd;
	void (*built_in)(char **av);

	cmd = parse(line);

	built_in = find_build_in(cmd->path);

	if (built_in != NULL)
	{
		built_in(cmd->av);
	}
	else
	{
		exec(cmd);
		free(cmd->path);
	}

	free(cmd->av);
	free(cmd);
}
