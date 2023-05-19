#ifndef TOKENS_H
#define	TOKENS_H

#include <stdlib.h>
#include <string.h>

/**
* struct node - The given code snippet defines a structure called node
* @data: This member is a pointer to a character
* @next: This member is a pointer to another token_t structure
*/

typedef struct node
{
	char *data;
	struct node *next;
} token_t;

token_t *add_token(token_t *head, char *token);
token_t *create_tokens(char *line, char *d);
size_t count_tokens(token_t *head);
void free_tokens(token_t *head);

#endif
