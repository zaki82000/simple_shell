#include "shell.h"

/**
 * interpret - interprets the line.
 * @info: a pointer to the struct that contains all shell info.
 * @line: a pointer to the line.
 */
void interpret(info_t *info, char *line)
{
	command_t *cmd;
	void (*built_in)(info_t *info, char **av);

	cmd = parse_line(line);

	built_in = find_build_in(cmd->path);

	if (built_in != NULL)
	{
		built_in(info, cmd->av);
	}
	else
	{
		exec(info, cmd);
		free(cmd->path);
	}

	free(cmd->av);
	free(cmd);
}
