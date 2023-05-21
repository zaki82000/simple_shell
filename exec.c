#include "shell.h"

/**
 * exec - executes the command.
 * @info: a pointer to the struct that contains all shell info.
 * @cmd: a pointer to the command.
 */
void exec(info_t *info, command_t *cmd)
{
	pid_t pid;
	int status;

	cmd->path = find_path(cmd->path);

	if (cmd->path == NULL)
	{
		info->status = 127;
		print_error(info, (cmd->av)[0], "not found\n");

		return;
	}
	else if (access(cmd->path, X_OK) == -1)
	{
		info->status = 126;
		print_error(info, (cmd->av)[0], NULL);

		return;
	}

	pid = fork();

	if (pid == 0)
	{
		execve(cmd->path, cmd->av, environ);
	}
	else
		wait(&status);

	info->status = WEXITSTATUS(status);
}

/**
 * find_path - finds the full path of the file by search in PATH env.
 * @file: a pinter to the file name.
 *
 * Return: a pointer to the full path, NULL if it not found.
 */
char *find_path(char *file)
{
	char *PATH, *PATH_dup, *path;
	token_t *dirs, *currdir;

	if (access(file, F_OK) == 0)
		return (_strdup(file));

	PATH = getenv("PATH");

	if (PATH == NULL)
		return (NULL);

	PATH_dup = _strdup(PATH);

	if (PATH_dup == NULL)
		return (NULL);

	dirs = create_tokens(PATH_dup, ":");

	if (dirs == NULL)
		return (NULL);

	currdir = dirs;

	while (currdir != NULL)
	{
		path = create_path(currdir->data, file);

		if (access(path, F_OK) == 0)
		{
			free(PATH_dup);
			free_tokens(&dirs);
			return (path);
		}
		free(path);
		currdir = currdir->next;
	}
	free(PATH_dup);
	free_tokens(&dirs);
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
