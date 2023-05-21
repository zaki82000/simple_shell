#include "shell.h"

/**
 * main - UNIX command line interpreter.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: status code.
 */
int main(int ac, char **av)
{
	info_t info = {av[0], 0, 0};

	if (ac >= 2)
	{
		FILE *file;

		file = fopen(av[1], "r");

		if (file != NULL)
		{
			info.file_path = av[1];
			shell_non_interactive(&info, file);
			fclose(file);
		}
		else
		{
			info.status = 2;
			print_error(&info, av[1], NULL);
		}
	}
	else
	{
		if (isatty(STDIN_FILENO) == 1)
			shell_interactive(&info);
		else
			shell_non_interactive(&info, stdin);
	}

	return (info.status);
}
