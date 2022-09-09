#include "shell.h"
/**
 * cmd_sys - command cal system execute
 *
 * @term: parameter
 * Return: int
 */
int cmd_sys(term_t term)
{
char *var[] = {"exit", "setenv", "unsetenv", "cd", "env", NULL};
int (*func[])(term_t) = {cmd_exit, _setenv, _unsetenv,
_chdir, cmd_env, cmd_run};
if (strcmp(term.argv[0], var[0]) == 0)
{
return ((*func[0])(term));
}
if (strcmp(term.argv[0], var[1]) == 0)
{
return ((*func[1])(term));
}
if (strcmp(term.argv[0], var[2]) == 0)
{
return ((*func[2])(term));
}
if (strcmp(term.argv[0], var[3]) == 0)
{
return ((*func[3])(term));
}
if (strcmp(term.argv[0], var[4]) == 0)
{
return ((*func[4])(term));
}
return ((*func[5])(term));
}
