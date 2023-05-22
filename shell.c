#include "shell.h"

info_t info;

/**
 * main - UNIX command line interpreter.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: status.
 */
int main(int ac, char **av)
{
	info.file_path = av[0];
	info.line_number = 0;
	info.child_pid = 0;
	info.status = 0;

	signal(SIGINT, handle_sigint);

	if (ac >= 2)
	{
		FILE *file;

		file = fopen(av[1], "r");

		if (file != NULL)
		{
			info.file_path = av[1];
			shell_non_interactive(file);

			fclose(file);
		}
		else
		{
			info.status = 2;
			print_error(av[1], NULL);
		}
	}
	else
	{
		if (isatty(STDIN_FILENO) == 1)
			shell_interactive();
		else
			shell_non_interactive(stdin);
	}

	return (info.status);
}
