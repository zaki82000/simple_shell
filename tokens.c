#include "shell.h"

/**
* create_tokens - creates an array of tokens from line;
* @line: a pointer to the line.
* @d: a set of bytes that delimit the tokens in the parsed string.
*
* Return: a pointer to the array of tokens.
*/
char **create_tokens(char *line, char *d)
{
	char *token, **tokens;
	int i;

	tokens = malloc(sizeof(char **));

	token = strtok(line, d);

	for (i = 1; token != NULL; i++)
	{
		tokens[i - 1] = token;
		tokens = _realloc(
				tokens,
				i * (sizeof(char *)),
				(i + 1) * sizeof(char *));

		token = strtok(NULL, d);
	}

	tokens[i - 1] = NULL;

	return (tokens);
}
