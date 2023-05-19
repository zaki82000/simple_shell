#include "shell.h"

/**
 * _realloc - function that reallocates a memory block.
 * @ptr: a pointer to the memory block that previously allocated.
 * @old_size: the  old size of the old memory block.
 * @new_size: the new size of the new memory block.
 *
 * Return: a pointer to the new memory block.
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
