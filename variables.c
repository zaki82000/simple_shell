#include "shell.h"

/**
 * new_variable - creates new variable.
 * @name: the name of the variable.
 * @value: the value of the variable.
 *
 * Return: a pointer to the variable.
 */
variable_t *new_variable(char *name, char *value)
{
	variable_t *new = malloc(sizeof(variable_t));

	if (new == NULL)
		return (NULL);

	new->name = _strdup(name);
	new->value = _strdup(value);
	new->next = NULL;

	return (new);
}

/**
 * set_variable - sets variable if exist, adds new one if not.
 * @head: a pointer to pointer that points to the head of list.
 * @name: the name of the variable.
 * @value: the value of the varible.
 *
 * Return: a pointer to the variable.
 */
variable_t *set_variable(variable_t **head, char *name, char *value)
{
	variable_t *curr = NULL;

	if (*head == NULL)
	{
		*head = new_variable(name, value);
		return (*head);
	}

	curr = *head;

	while (curr->next != NULL)
	{
		if (strcmp(curr->name, name) == 0)
			break;

		curr = curr->next;
	}

	if (strcmp(curr->name, name) == 0)
	{
		free(curr->value);
		curr->value = _strdup(value);

		return (curr);
	}

	curr->next = new_variable(name, value);
	return (curr);
}

/**
 * unset_variable - removes a variable.
 * @head: a pointer to pointer that points to the head of list.
 * @name: the name of the variable.
 */
void unset_variable(variable_t **head, char *name)
{
	variable_t *prev = NULL, *curr = NULL;

	curr = *head;

	while (curr != NULL)
	{
		if (_strcmp(curr->name, name) == 0)
		{
			if (prev == NULL)
			{
				*head = curr->next;
				free(curr->name);
				free(curr->value);
				free(curr);
				return;
			}

			prev->next = curr->next;
			free(curr->name);
			free(curr->value);
			free(curr);
			return;
		}

		prev = curr;
		curr = curr->next;
	}
}

/**
 * free_variables - frees variable list.
 * @head: a pointer to pointer that points to the head of list.
 */
void free_variables(variable_t **head)
{
	variable_t *curr = NULL, *next = NULL;

	curr = *head;

	while (curr != NULL)
	{
		next = curr->next;

		free(curr->name);
		free(curr->value);
		free(curr);

		curr = next;
	}

	*head = NULL;
}

/**
 * get_variable - gets variable value.
 * @head: a pointer to pointer that points to the head of list.
 * @name: the name of the varible.
 *
 * Return: the value of the variable.
 */
char *get_variable(variable_t *head, char *name)
{
	while (head != NULL)
	{
		if (_strcmp(head->name, name) == 0)
			return (head->value);

		head = head->next;
	}

	return (NULL);
}
