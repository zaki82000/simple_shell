#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

/**
 * struct info - a struct that contians all global shell info.
 * @file_path: the path of the file.
 * @line_number: the number of the current line.
 * @child_pid: the child process id.
 * @status: the status of the last command.
 */
typedef struct info
{
	char *file_path;
	int line_number;
	pid_t child_pid;
	int status;
} info_t;

/* __________ shell_non_interactive.c __________ */

void shell_non_interactive(FILE *file);

/* __________ shell_interactive.c __________ */

void shell_interactive(void);
ssize_t prompt_and_getline(char *prompt, char **line, size_t *n);

/* __________ interpret.c __________ */

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

void interpret(char *line);

/* __________ parse.c __________ */

command_t *parse(char *line);

/* __________ built_ins.c __________ */

/**
 * struct built_in - a struct that represent a built-in.
 * @name: a pointer to the name of the built-in.
 * @fun: a pointer to the built-in function.
 */
typedef struct built_in
{
	char *name;
	void (*fun)(char **av);
} built_in_t;

void (*find_build_in(char *name))(char **av);
void _exit_(char **av);
void _env_(char **av);

/* __________ exec.c _________ */

void exec(command_t *cmd);
char *find_path(char *file);
char *create_path(char *dir, char *file);

/* __________ handle_sigint.c __________ */

void handle_sigint(int);

/* __________ error.c __________ */

void print_error(char *cmd, char *msg);

/* _________ tokens.c __________ */

/**
* struct token - a struct that repesent a token node.
* @t: a pinter to the token.
* @next: a pointer to the next node.
*/
typedef struct token
{
	char *t;
	struct token *next;
} token_t;

token_t *add_token(token_t *head, char *token);
token_t *create_tokens(char *str, char *d);
size_t count_tokens(token_t *head);
void free_tokens(token_t **head);
char **tokens_to_av(token_t *head);

/* __________ utils.c __________ */

char *envdup(char *name);

/* __________ string_utils.c __________ */

int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
int is_empty(char *str);

/* __________ global varibales __________ */

extern char **environ;
extern info_t info;

#endif
