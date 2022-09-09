#include "shell.h"
/**
 * cmd_run - execution
 *
 * @term: parameter
 * Return: int
 */
int cmd_run (term_t term)
{
pid_t id;
    
id  = fork();
if (id == -1)
{
perror("./hsh");
return (-1);
}
if (id == 0)
{
term.cmd = search_cmd_path(term);
if (execve(term.cmd, term.argv, term.envp) == -1)
{
perror("./hsh");
}
}
else
{
wait(&term.status);
}
return (0);
}
