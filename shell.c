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
		int fd;

		fd = open(av[1], O_RDONLY);

		if (fd != -1)
		{
			info.file_name = av[1];
			shell_non_interactive(&info, fd);
			close(fd);
		}
		else
		{
			/* needs error handling */
		}
	}
	else
	{
		if (isatty(STDIN_FILENO) == 1)
			shell_interactive(&info);
		else
			shell_non_interactive(&info, STDIN_FILENO);
	}

	return (info.status);
}
