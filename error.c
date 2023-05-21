#include "shell.h"

/**
 * print_error - prints a formated error message.
 * @info: a pointer to the struct that contians all shell info.
 * @cmd: a pointer to command string.
 * @msg: a pointer to error message.
 */
void print_error(info_t *info, char *cmd, char *msg)
{
	dprintf(STDERR_FILENO,
		"%s: %d: %s: %s",
		info->file_path,
		info->line_number,
		cmd,
		msg != NULL ? msg : "");

	if (msg == NULL)
		perror("");
}
