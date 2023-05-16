#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

#endif
