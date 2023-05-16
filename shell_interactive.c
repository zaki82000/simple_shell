#include "shell.h"

/**
 * prompt_and_getline - prompts the user to enter a line & reads it from stdin.
 * @prompt: a pointer to to prompt string.
 * @line: a pointer to a pointer that will points to line buffer.
 * @n: a pointer to a variable that will be set to the size of line buffer.
 *
 * Return: the number of characters on success, -1 on error.
 */
int prompt_and_getline(char *prompt, char **line, size_t *n)
{
	if (prompt != NULL)
		write(STDOUT_FILENO, prompt, strlen(prompt));

	return (getline(line, n, stdin));
}

/**
 * shell_interactive - runs shell in interactive mode.
 * @info: a pointer to struct that contains all current shell info.
 */
void shell_interactive(info_t *info)
{
	char *prompt = "($) ";
	char *line = NULL;
	size_t n = 0;

	while (prompt_and_getline(prompt, &line, &n) != -1)
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

	write(STDOUT_FILENO, "\n", 1);

	free(line);
}
