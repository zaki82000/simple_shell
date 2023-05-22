#include "shell.h"

/**
 * print_error - prints a formated error message.
 * @cmd: a pointer to command string.
 * @msg: a pointer to error message.
 */
void print_error(char *cmd, char *msg)
{
	dprintf(STDERR_FILENO,
		"%s: %d: %s: %s",
		info.file_path,
		info.line_number,
		cmd,
		msg != NULL ? msg : "");

	if (msg == NULL)
		perror("");
}
