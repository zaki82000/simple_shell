#include "shell.h"

/**
 * interpret - interprets the line.
 * @info: a pointer to the struct that contains all shell info.
 * @line: a pointer to the line.
 */
void interpret(info_t *info, char *line)
{
	command_t *cmd;

	cmd = parse_line(line);
	exec(info, cmd);

	free(cmd->path);
	free(cmd->av);
	free(cmd);
}
