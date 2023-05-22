#include "shell.h"

/**
 * shell_interactive - runs shell in interactive mode.
 */
void shell_interactive(void)
{
	char *prompt = "($) ";
	char *line = NULL;
	size_t n;

	while (prompt_and_getline(prompt, &line, &n) != -1)
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
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * prompt_and_getline - prompts & gets line from stdin.
 * @prompt: a pointer to the prompt string.
 * @line: a pointer to the line buffer.
 * @n: a pointer to the buffer size.
 *
 * Return: the number of characters on success, -1 on error.
 */
ssize_t prompt_and_getline(char *prompt, char **line, size_t *n)
{
	if (prompt != NULL)
		write(STDOUT_FILENO, prompt, strlen(prompt));

	return (getline(line, n, stdin));
}
