#include "shell.h"

/**
 * handle_sigint - handles SIGINT signal.
 * @n: _
 */
void handle_sigint(__attribute__((unused))int n)
{
	if (info.child_pid != 0)
	{
		kill(info.child_pid, SIGTERM);
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		write(STDOUT_FILENO, "\n($) ", 5);
}
