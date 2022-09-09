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
char *str, *pwd;
if (strcmp(term.argv[0], "cd") == 0)
{
    pwd = "PWD=";
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
            pwd = _strcat(pwd, term.argv[1]);
            pwd = strcat(pwd, "\0");
            cmd_pwd(pwd);
            return (chdir(term.argv[1]));
        }
        else
        {
            perror("./hsh");
            return (-1);
        }
    }
    pwd = _strcat(pwd, _getenv("HOME"));
    cmd_pwd(pwd);
    return (chdir(_getenv("HOME")));
}
return (-1);
}

void cmd_pwd(char *pwd)
{
    size_t i, j;
    char *str = "PWD=";
    for (i = 0; environ[i] != NULL; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (environ[i][j] != str[j])
            {
                break;
            }
        }
        if (j == 4)
        {
            environ[i] = pwd;
            return;
        }
    }
}