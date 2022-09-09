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
char *str;
if (strcmp(term.argv[0], "cd") == 0)
{
    if (term.argv[1] != NULL)
    {
        if (term.argv[1][0] == '$')
        {
            str = malloc(strlen(term.argv[1]) * sizeof(char) - 1);
            str = term.argv[1] + 1;
            term.argv[1] = _getenv(str);
        }
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
