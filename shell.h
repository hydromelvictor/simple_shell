#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct shell - general variables of the shell
 * @argv: arguments for shell
 * @envp: environment vars
 * @cmd: command for shell
 * @line: comand line
 * @status: command status
 */
typedef struct shell
{
char **argv;
char **envp;
char *cmd;
char *line;
int status;
} term_t;

char **cmd_args(char *arg, const char *delim);
char **__realloc(char **args, size_t n);
int cmd_sys(term_t term);

#endif
