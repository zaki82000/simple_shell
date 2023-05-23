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

/* _________ variables.c __________ */

/**
* struct variable - a struct represents a variable node.
* @name: a pointer to the name of the variable.
* @value: a pointer the value of the variable.
* @next: a pointer to the next node.
*/
typedef struct variable
{
	char *name;
	char *value;
	struct variable *next;
} variable_t;

variable_t *new_variable(char *name, char *value);
variable_t *set_variable(variable_t **head, char *name, char *value);
void unset_variable(variable_t **head, char *name);
void free_variables(variable_t **head);
char *get_variable(variable_t *head, char *name);

/* _________ tokens.c __________ */

char **create_tokens(char *line, char *d);

/* __________ parse.c __________ */

command_t *parse(char *line);
void handle_comments(char *line);
void handle_variables(char **tokens);

/* __________ built_in.c __________ */

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

void print_error(char *lmsg, char *cmd, char *tmsg);

/* __________ utils.c __________ */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *envdup(char *name);
void set_nvariable(variable_t **head, char *name, int n);
void set_status(int status);

/* __________ strings_utils.c __________ */

int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
int is_empty(char *str);

/* __________ numbers_utils.c __________ */

char *int_to_str(int num);

/* __________ global varibales __________ */

/**
 * struct info - a struct that contians all global shell info.
 * @path: the path of the file.
 * @count: the lines count.
 * @variables: the variables linked list.
 * @child_pid: the child process id.
 * @status: the status of the last command.
 */
typedef struct info
{
	char *path;
	int count;
	variable_t *variables;
	pid_t child_pid;
	int status;
} info_t;

extern char **environ;
extern info_t info;

#endif
