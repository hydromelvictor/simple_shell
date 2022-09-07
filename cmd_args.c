#include "shell.h"
/**
 * cmd_args - arguments in tables
 *
 * @arg: paramter
 * @delim: paramter
 * Return: char**
 */
char **cmd_args(char *arg, const char *delim)
{
char **args;
size_t len = 5, i = 0;
if (arg == NULL)
{
perror("./hsh");
return (NULL);
}
args = malloc(len * sizeof(char *));
if (args == NULL)
{
perror("./hsh");
return (NULL);
}
args[0] = strtok(arg, delim);
while (args[i] != NULL)
{
i++;
if (i == len)
{
args = __realloc(args, len);
if (args == NULL)
{
perror("./hsh");
return (NULL);
}
}
args[i] = strtok(NULL, delim);
}
return (args);
}


