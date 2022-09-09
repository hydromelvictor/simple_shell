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

extern char **environ;

char **cmd_args(char *arg, const char *delim);
char **__realloc(char **args, size_t n);
int cmd_sys(term_t term);
int cmd_run (term_t term);

char *search_path(void);
char *search_cmd_path(term_t term);
int exec_permission(char *cmd);

int cmd_exit(term_t term);
int cmd_env(term_t term);
int _setenv(term_t term);
char *_getenv(const char *name);
int _unsetenv(term_t term);
int _chdir(term_t term);

char *_strdup(const char *src);
char *_strcat(char *dest, char *src);
void cmd_pwd(char *pwd);
#endif
