#include "shell.h"

/**
* _int_to_str - _
* @num: _
* @temp: _
*/
void _int_to_str(unsigned int num, char **temp)
{
	if (num > 9)
		_int_to_str(num / 10, temp);

	**temp = (num % 10) + 48;
	(*temp)++;
}

/**
* int_to_str - converts an integer into a string
* @num: the number to be converted.
*
* Return: a pointer to the buffer.
*/
char *int_to_str(int num)
{
	char *buff, *temp;

	buff = malloc(16 * sizeof(char));

	if (buff == NULL)
		return (NULL);

	temp = buff;

	if (num < 0)
	{
		*temp++ = '-';
		num *= -1;
	}

	_int_to_str(num, &temp);

	*temp = '\0';

	return (buff);
}
