#include "shell.h"

/**
 * _strlen - function to returns the length of a string @count is input.
 * @s: input .
 * Return: return count.
 **/

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
* _strcmp - function that compares two strings.
* @s1: first string
* @s2: second string
*
* Return: 0 if stringes ate same. ASCII code defference otherwise
*/
int _strcmp(char *s1, char *s2)

{

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
		{

		s1++;
		s2++;
		}

		else

			return (*s1 - *s2);

	}
	return (*s1 - *s2);

}

/**
 * _strncmp - Compare two strings up to a specified number of characters.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than 0,
 *	depending on the comparison result.
 *	- Negative value if str1 is less than str2.
 *	- Positive value if str1 is greater than str2.
 *	- Zero if both strings are equal up to n characters.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}

		if (str1[i] == '\0')
		{
			return (0);
		}
	}

	return (0);
}


/**
*_strdup - function that returns a pointer to a newly allocated space,
* in mem*ory , which contains,
*a copy of the string given as a parameter,
*ptr: pointer to *new space in memory,
*ptr_temp: pointer eqwal ptr pointer,
*temp: pointer to string,temp_size: lenght to string str.
*@str: pointer to string.
*Return: return NULL if srt null, in end return pointer to new space in memory.
*/

char *_strdup(char *str)
{
	char *ptr;
	char *ptr_temp;
	char *temp = str;
	int temp_size;



	if (temp == NULL)
		return (NULL);

	temp_size = strlen(temp);

	ptr = (char *) malloc(temp_size + 1);
	ptr_temp = ptr;

	if (ptr == NULL)
		return (NULL);

	while (*temp)
		*ptr_temp++ = *temp++;

	*ptr_temp = '\0';

	return (ptr);

}
