#include "shell.h"

/**
 * _alias_ - alias built-in command.
 * @av: argument vector.
 */
void _alias_(char **av)
{
	int i;

	if (av[1] == NULL)
	{
		print_aliases(info.aliases);
		return;
	}

	for (i = 1; av[i]; i++)
	{
		if (strspn("=", av[i]) > 0)
		{
			set_alias(&(info.aliases), av[i]);
		}
		else
		{
			print_alias(info.aliases, av[i]);
		}
	}
}

/**
 * set_alias - sets an alias if exist, add new one if not.
 * @head: a pointer to the head of aliases linked list.
 * @name_value: the name and value of the alias in form name='value'.
 */
void set_alias(variable_t **head, char *name_value)
{
	char *name = strtok(name_value, "=");
	char *value = strtok(NULL, "'");

	set_variable(head, name, value);
}

/**
 * print_alias - prints an alias.
 * @head: a pointer to the head of aliases linked list.
 * @name: the name of alias.
 */
void print_alias(variable_t *head, char *name)
{
	variable_t *alias = get_variable(head, name);

	if (alias != NULL)
	{
		dprintf(STDOUT_FILENO, "%s='%s'\n", alias->name, alias->value);
	}
	else
	{
		set_status(1);
		dprintf(STDOUT_FILENO, "alias: %s not found\n", name);
	}
}

/**
 * print_aliases - prints all aliases.
 * @head: a pointer to the head of aliases linked list.
 */
void print_aliases(variable_t *head)
{
	while (head != NULL)
	{
		dprintf(STDOUT_FILENO, "%s='%s'\n", head->name, head->value);
		head = head->next;
	}
}
