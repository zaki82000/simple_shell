#include "shell.h"

/**
 * _realloc - reallocates a block of memory.
 * @ptr: a pointer to the old memory block.
 * @old_size: the size of the old memory block.
 * @new_size: the size of the new memor block.
 *
 * Return: a pointer tp the new memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i, min;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size == new_size && ptr != NULL)
		return (ptr);

	min = old_size < new_size ? old_size : new_size;

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (ptr);

	if (ptr == NULL)
	{
		ptr = new_ptr;
		return (ptr);
	}

	for (i = 0; i < min; i++)
		((char *) new_ptr)[i] = ((char *) ptr)[i];

	free(ptr);
	ptr = new_ptr;

	return (ptr);
}

/**
 * envdup - duplicates an enviornment variable.
 * @name: the name of the enviornment variable.
 *
 * Return: a pointer to duplicated variable.
 */
char *envdup(char *name)
{
	char *env, *dup;

	env = getenv(name);

	if (env == NULL)
		return (NULL);

	dup = _strdup(env);

	if (dup == NULL)
		return (NULL);

	return (dup);
}
/**
* set_nvariable - sets numeric variable if exist, adds new one if not.
* @head: a pointer to pointer that points to the head of list.
* @name: the name of the variable.
* @n: the numeric value of the varible.
*/
void set_nvariable(variable_t **head, char *name, int n)
{
	char *buff = int_to_str(n);

	set_variable(head, name, buff);
	free(buff);
}

/**
* set_status - sets status and its variable.
* @status: the status.
*/
void set_status(int status)
{
	info.status = status;
	set_nvariable(&(info.variables), "?", status);
}
