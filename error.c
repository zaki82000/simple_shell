#include "shell.h"

/**
 * print_error - prints a formated error message.
 * @info: a pointer to the struct that contians all shell info.
 * @lmsg: a pointer to the leading message.
 * @cmd: a pointer to command string.
 * @tmsg: a pointer to trailing message.
 */
void print_error(info_t *info, char *lmsg, char *cmd, char *tmsg)
{
	dprintf(STDERR_FILENO,
		"%s: %d: %s%s: %s",
		info->file_path,
		info->line_number,
		(lmsg != NULL ? lmsg : ""),
		cmd,
		(tmsg != NULL ? tmsg : ""));

	if (tmsg == NULL)
		perror("");
}
