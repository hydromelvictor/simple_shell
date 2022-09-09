#include "shell.h"

/**
 * _chdir - change directory
 *
 * @term: parameter
 * Return: int
 */
int _chdir(term_t term)
{
struct  stat buf;
if (strcmp(term.argv[0], "cd") == 0)
{
    if (term.argv[1] != NULL)
    {
        if (stat(term.argv[1], &buf) == 0)
        {
            return (chdir(term.argv[1]));
        }
        else
        {
            perror("./hsh");
            return (-1);
        }
    }
    return (chdir(_getenv("HOME")));
}
return (-1);
}
