#include "shell.h"

/**
 * add_token - Adds a new token to the linked list.
 * @head: The head of the linked list.
 * @token: The token to be added.
 *
 * Return: return the updated head of the linked list.
 */

token_t *add_token(token_t *head, char *token)
{
	token_t *temp = head;
	token_t *new_token = token;

	new_token = malloc(sizeof(token));

	if (new_token == NULL)
		return (NULL);

	new_token->data = token;
	new_token->next = NULL;

	if (head == NULL)
	{
		head = new_token;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new_token;
	}

	return (new_token);
}

/**
 * count_tokens - Counts the number of tokens in a linked list.
 * @head: The head of the linked list.
 *
 * Return: return the number of tokens in the linked list.
 */

size_t count_tokens(token_t *head)
{
	token_t *temp = head;
	size_t count = 1;

	if (temp == NULL)
		return (-1);


	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}

	return (count);
}

/**
* free_tokens - function to free the memory.
* @head: The head of the linked list.
*/

void free_tokens(token_t *head)
{

	token_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * create_tokens - Create a linked list of tokens from a line of text.
 * @line: The input line of text.
 * @d: The delimiter used to separate tokens.
 *
 * Return: A pointer to the head of the linked list of tokens.
 */

token_t *create_tokens(char *line, char *d)
{
	token_t *head = NULL;
	char *token;

	token = strtok(line, d);

	while (token != NULL)
	{
		head = add_token(head, token);
		token = strtok(NULL, d);
	}

	return (head);
}
