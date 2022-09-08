#include "shell.h"
/**
* search_path - search the path in environment
*
* @void: parameter
* Return: char*
*/
char *search_path(void)
{
char *path = "PATH=";
int i;
for (i = 0; environ[i] != NULL; i++)
{
if (strstr(environ[i], path) == environ[i])
{
break;
}
}
return (environ[i]);
}

/**
* search_cmd_path - searching the path of the cmd
*
* @term: shell variables
* Return: char*
*/
char *search_cmd_path(term_t term)
{
char *path;
char **path_tab;
int i = 0;
if (strpbrk(term.argv[0], "/"))
{
if (exec_permission(term.argv[0]) == 0)
{
return (term.argv[0]);
}
else
{
return (NULL);
}
}
else
{
path = strdup(search_path() + 5);
path_tab = cmd_args(path, ":");
while (path_tab[i] != NULL)
{
term.cmd = strcat(path_tab[i], "/");
term.cmd = strcat(term.cmd, term.argv[0]);
if (exec_permission(term.cmd) == 0)
{
free(path);
free(path_tab);
return (term.cmd);
}
i++;
}
free(path);
free(path_tab);
}
return (NULL);
}

/**
* exec_permission - permission for execution
*
* @cmd: command
* Return: int
*/
int exec_permission(char *cmd)
{
struct stat buf;
if (stat(cmd, &buf) == 0)
{
if (access(cmd, X_OK) == 0)
{
return (0);
}
else
{
perror("./hsh");
return (-1);
}
}
return (-1);
}
