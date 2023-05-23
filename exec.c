#include "shell.h"

/**
 * exec - executes the command.
 * @cmd: a pointer to the command.
 */
void exec(command_t *cmd)
{
	pid_t pid;
	int status;

	cmd->path = find_path(cmd->path);

	if (cmd->path == NULL)
	{
		set_status(127);
		print_error(NULL, (cmd->av)[0], "not found\n");
		return;
	}

	if (access(cmd->path, X_OK) == -1)
	{
		set_status(126);
		print_error(NULL, (cmd->av)[0], "Permission denied\n");
		return;
	}

	pid = fork();
	info.child_pid = pid;

	if (pid == 0)
	{
		execve(cmd->path, cmd->av, environ);
	}
	else
		wait(&status);

	if (WIFSIGNALED(status))
	{
		set_status(130);
	}
	else
	{
		set_status(WEXITSTATUS(status));
	}

	info.child_pid = 0;
}

/**
 * find_path - finds the full path of the file by search in PATH env.
 * @file: a pinter to the file name.
 *
 * Return: a pointer to the full path, NULL if it not found.
 */
char *find_path(char *file)
{
	char *PATH, *path, **dirs;
	int i;

	if (access(file, F_OK) == 0)
		return (_strdup(file));

	PATH = envdup("PATH");

	if (PATH == NULL)
		return (NULL);

	dirs = create_tokens(PATH, ":");

	if (dirs == NULL)
		return (NULL);

	for (i = 0; dirs[i]; i++)
	{
		path = create_path(dirs[i], file);

		if (access(path, F_OK) == 0)
		{
			free(PATH);
			free(dirs);

			return (path);
		}

		free(path);
	}

	free(PATH);
	free(dirs);

	return (NULL);
}

/**
 * create_path - creates a path from dir path and file name.
 * @dir: a pointer to the dir path.
 * @file: a pointer to the file name.
 *
 * Return: a pointer to the full file path.
 */
char *create_path(char *dir, char *file)
{
	char *path;
	int i, j = 0;

	if (dir == NULL || file == NULL)
		return (NULL);

	path = malloc(strlen(dir) + strlen(file) + 2);

	if (path == NULL)
		return (NULL);


	for (i = 0; dir[i]; i++, j++)
		path[j] = dir[i];

	path[j] = '/';
	j++;

	for (i = 0; file[i]; i++, j++)
		path[j] = file[i];

	path[j] = '\0';

	return (path);
}
