#include "shell.h"

/**
 * print_error - prints a formated error message.
 * @lmsg: a pointer to leading  message.
 * @cmd: a pointer to command string.
 * @tmsg: a pointer to trealing  message.
 */
void print_error(char *lmsg, char *cmd, char *tmsg)
{
	dprintf(STDERR_FILENO,
		"%s: %d: %s%s: %s",
		info.path,
		info.count,
		lmsg != NULL ? lmsg : "",
		cmd,
		tmsg != NULL ? tmsg : "");

	if (tmsg == NULL)
		perror("");
}
