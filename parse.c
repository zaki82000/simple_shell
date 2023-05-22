#include "shell.h"

/**
 * parse - parses the line to be a valid command.
 * @line: a pointer to the line.
 *
 * Return: a pointer to the command.
 */
command_t *parse(char *line)
{
	command_t *cmd;
	token_t *tokens;

	cmd = malloc(sizeof(command_t));

	if (cmd == NULL)
		return (NULL);

	tokens = create_tokens(line, " \n\t");

	/* variables and alias replacement will be here */

	cmd->path = tokens->t;
	cmd->av = tokens_to_av(tokens);

	free_tokens(&tokens);

	return (cmd);
}
