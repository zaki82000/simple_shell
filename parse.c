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
	char **tokens;

	handle_comments(line);

	cmd = malloc(sizeof(command_t));

	if (cmd == NULL)
		return (NULL);

	tokens = create_tokens(line, " \n\t");

	handle_variables(tokens);

	cmd->path = tokens[0];
	cmd->av = tokens;

	return (cmd);
}

/**
 * handle_comments - removes comments from a line.
 * @line: a pointer to the line.
 */
void handle_comments(char *line)
{
	int i;

	if (line == NULL)
		return;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '#' && line[i - 1] == ' ')
		{
			line[i] = '\0';
			return;
		}
	}
}

/**
* handle_variables - handles variables replacement.
* @tokens: an array of strings.
*/
void handle_variables(char **tokens)
{
	int i;
	char *var;

	for (i = 0; tokens[i]; i++)
	{
		if (tokens[i][0] == '$')
		{
			if (tokens[i][1] == '\0')
				continue;

			var = get_variable(info.variables, &(tokens[i][1]));

			if (var != NULL)
			{
				tokens[i] = var;
				continue;
			}

			var = getenv(&(tokens[i][1]));

			if (var != NULL)
			{
				tokens[i] = var;
				continue;
			}

			tokens[i] = get_variable(info.variables, "NON");
		}
	}
}
