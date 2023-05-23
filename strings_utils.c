#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @str: a poiner to the string.
 *
 * Return: length of the string.
 */
int _strlen(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}

	return (count);
}

/**
 * _strcmp - compares two strings.
 * @str1: a pointer to first string.
 * @str2: a pointer to second string.
 *
 * Return: 0 if both stringes ate same. ASCII code defference otherwise.
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (*str1 - *str2);
	}

	return (*str1 - *str2);
}

/**
 * _strncmp - compares two strings up to a specified number of characters.
 * @str1: a pointer to first string.
 * @str2: a pointer to second string.
 * @n: the maximum number of characters to compare.
 *
 * Return:
 *	0 if both strings are equal up to n characters,
 *	ASCII code defference otherwise.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);

		if (str1[i] == '\0')
			return (0);
	}

	return (0);
}

/**
 * _strdup - duplicates a string to a new allocated space.
 * @str: a pointer to string.
 *
 * Return: a pointer to new space in memory, NULL on error.
 */
char *_strdup(char *str)
{
	char *ptr;
	char *ptr_temp;
	char *temp = str;
	int temp_size;

	if (temp == NULL)
		return (NULL);

	temp_size = _strlen(temp);

	ptr = (char *) malloc(temp_size + 1);
	ptr_temp = ptr;

	if (ptr == NULL)
		return (NULL);

	while (*temp)
		*ptr_temp++ = *temp++;

	*ptr_temp = '\0';

	return (ptr);
}

/**
* is_empty - checks if a string is empty.
* @str: a pointer to the string.
*
* Return: 1 if the string is empty, 0 if its not empty.
*/
int is_empty(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			return (0);
		}
	}

	return (1);
}
