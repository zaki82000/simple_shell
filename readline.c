#include "shell.h"

/**
 * readline - reads one line from a file.
 * @fd: the file descriptor.
 *
 * Return: a pointer to the line.
 */
char *readline(int fd)
{
	char *line, *ptr;
	int size, readed, total_readed = 0;

	line = malloc((BUFFSIZE + 1) * sizeof(char));

	if (line == NULL)
		return (NULL);

	size = BUFFSIZE + 1;
	ptr = line;
	while (true)
	{
		readed = read(fd, ptr, BUFFSIZE);
		if (readed <= 0)
		{
			if (total_readed != 0)
			{
				ptr[readed] = '\0';
				line = _realloc(line, size, _strlen(line) + 1);
				return (line);
			}

			free(line);
			return (NULL);
		}
		for (int i = 0; i < readed; i++)
		{
			if (ptr[i] == '\n')
			{
				ptr[i + 1] = '\0';
				line = _realloc(line, size, _strlen(line) + 1);
				lseek(fd, (i - readed) + 1, SEEK_CUR);
				return (line);
			}
		}
		total_readed += readed;
		line = _realloc(line, size, size + BUFFSIZE);
		size += BUFFSIZE;
		ptr = (line + total_readed);
	}
}
