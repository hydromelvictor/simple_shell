#include "shell.h"
/**
 * cmd_sys - command cal system execute
 *
 * @term: parameter
 * Return: int
 */
int cmd_sys(term_t term)
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
        term.cmd = term.argv[0];

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
