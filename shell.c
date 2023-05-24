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
	{
		FILE *file;

		file = fopen(av[1], "r");

		if (file != NULL)
		{
			info.path = av[1];
			shell_non_interactive(file);

			fclose(file);
		}
		else
		{
			set_status(2);

			if (errno == ENOENT)
				print_error("cannot open ", av[1], "No such file\n");
			else
				print_error("cannot open ", av[1], NULL);
		}
	}
	else
	{
		if (isatty(STDIN_FILENO) == 1)
			shell_interactive();
		else
			shell_non_interactive(stdin);
	}

	free_variables(&(info.variables));

	return (info.status);
}
