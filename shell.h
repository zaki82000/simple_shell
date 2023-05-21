#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFSIZE 128

extern char **environ;

/**
 * struct info - a struct that contians all current shell info.
 * @file_path: the path of the file.
 * @line_number: the number of the current line.
 * @status: the status of the last command.
 */
typedef struct info
{
	char *file_path;
	int line_number;
	int status;
} info_t;

/**
 * struct command - a struct that represent a command.
 * @path: a pointer to the command path.
 * @av: the argument vector of the command.
 */
typedef struct command
{
	char *path;
	char **av;
} command_t;

void shell_interactive(info_t *info);
void shell_non_interactive(info_t *info, FILE *file);

char *readline(int fd);
void interpret(info_t *info, char *line);
command_t *parse_line(char *line);
void exec(info_t *info, command_t *cmd);
char *find_path(char *file);
char *create_path(char *dir, char *file);

/* built_ins */

/**
 * struct built_in - a struct that represent a built-in.
 * @name: a pointer to the name of the built-in.
 * @fun: a pointer to the built-in function.
 */
typedef struct built_in
{
	char *name;
	int (*fun)(info_t *info, char **av);
} built_in_t;

int (*find_build_in(char *name))(info_t *info, char **av);
int exit_shell(info_t info, char **av);
int env(info_t info, char **av);

/* error */

void print_error(info_t *info, char *cmd, char *msg);

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
void free_tokens(token_t **head);
char **tokens_to_av(token_t *head);

/* utils */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string utils */

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
int is_empty(char *s);

#endif
