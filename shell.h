#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct info - a struct that contians all current shell info.
 * @file_name: the name of the program file.
 * @line_number: the number of the current line.
 * @status: the status of the last command.
 */
typedef struct info
{
	char *file_name;
	int line_number;
	int status;
} info_t;

void shell_interactive(info_t *info);
void shell_non_interactive(info_t *info, FILE *file);


/* tokens */

/**
* struct token - The given code snippet defines a structure called token
* @data: This member is a pointer to a character
* @next: This member is a pointer to another token_t structure
*/
typedef struct token
{
	char *data;
	struct token *next;
} token_t;

token_t *add_token(token_t *head, char *token);
token_t *create_tokens(char *line, char *d);
size_t count_tokens(token_t *head);
void free_tokens(token_t *head);


/* utils */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string utils */

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);

#endif
