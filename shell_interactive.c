#include "shell.h"

/**
 * shell_interactive - runs shell in interactive mode.
 */
void shell_interactive(void)
{
	char *prompt = "($) ";
	size_t n = 0;

	while (prompt_and_getline(prompt, &(info.line), &n) != -1)
	{
		(info.count)++;

		if (is_empty(info.line) || info.line[0] == '#')
		{
			free(info.line);
			info.line = NULL;
			continue;
		}

		interpret(info.line);

		free(info.line);
		info.line = NULL;
	}

	free(info.line);
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
