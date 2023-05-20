#include "shell.h"

/**
 * prompt_and_readline - prompts & reads line from stdin.
 * @prompt: a pointer to the prompt string.
 *
 * Return: the number of characters on success, -1 on error.
 */
char *prompt_and_readline(char *prompt)
{
	if (prompt != NULL)
		write(STDOUT_FILENO, prompt, strlen(prompt));

	return (readline(STDIN_FILENO));
}

/**
 * shell_interactive - runs shell in interactive mode.
 * @info: a pointer to struct that contains all current shell info.
 */
void shell_interactive(info_t *info)
{
	char *prompt = "($) ";
	char *line;

	while ((line = prompt_and_readline(prompt)) != NULL)
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

	write(STDOUT_FILENO, "\n", 1);
}
