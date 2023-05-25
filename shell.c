#include "shell.h"

info_t info;

/**
* init - initalizes globale variables.
*/
void init(void)
{
	info.path = NULL;
	info.count = 0;
	info.line = NULL;
	info.aliases = NULL;
	info.variables = NULL;
	info.cmd = NULL;
	info.child_pid = 0;

	set_variable(&(info.variables), "NON", "");
	set_nvariable(&(info.variables), "$", getpid());
	set_status(0);

	signal(SIGINT, handle_sigint);
}


/**
 * main - UNIX command line interpreter.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: status.
 */
int main(int ac, char **av)
{
	init();
	info.path = av[0];

	if (ac >= 2)
		file_non_interactive(av[1]);
	else
	{
		if (isatty(STDIN_FILENO) == 1)
			shell_interactive();
		else
			shell_non_interactive(stdin);
	}

	free_variables(&(info.aliases));
	free_variables(&(info.variables));

	return (info.status);
}
