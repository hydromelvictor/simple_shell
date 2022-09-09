#include "shell.h"
/**
 * cmd_exit - exit the program
 *
 * @term: parameter
 */
int cmd_exit(term_t term)
{
    if (term.argv[1] != NULL)
    {
        term.status = atoi(term.argv[1]);
    }
    return (400);
}

/**
 * cmd_env - print the environment variables
 *
 */
int cmd_env(term_t term)
{
    size_t i;
    if (strcmp(term.argv[0], "env") == 0)
    {
        for (i = 0; environ[i] != NULL; i++)
        {
            printf("%s\n", environ[i]);
        }
        return (0);
    }
    return (-1);
}

/**
 * _setenv - change or add the new environment variable
 *
 * @name: parameter
 * @value: parameter
 * @overwrite: parameter
 * Return: int
 */
int _setenv(term_t term)
{
    char *str;
    size_t i;
    if (term.argv[1] != NULL && term.argv[2] != NULL)
    {
        str = _getenv(term.argv[1]);
        if (str == NULL)
        {
            for (i = 0; environ[i] != NULL; i++)
            ;
            environ[i] = _strdup(term.argv[1]);
            environ[i] = _strcat(environ[i], "=");
            environ[i] = _strcat(environ[i], _strdup(term.argv[2]));
            environ[i] = strcat(environ[i], "\0");
        }
        else
        {
            for (i = 0; str[i] != '\0'; i++)
            {
                if (str[i] == '=')
                {
                    break;
                }
            }
            str = strcat(str + i + 1,strdup(term.argv[2]));
            return (0);
        }
    }
    return (-1);
}

/**
 * _getenv - prin de specific environment variable
 * 
 * @name: parameter
 * Return: char* 
 */
char *_getenv(const char *name)
{
    size_t i;
    if (name != NULL)
    {
        for (i = 0; environ[i] != NULL; i++)
        {
            if (strncmp(environ[i], name, strlen(name)) == 0)
            {
                return (environ[i] + strlen(name) + 1);
            }
        }
    }
    return (NULL);
}

/**
 * _unsetenv - revome the specific environment variable
 *
 * @name: parameter
 * Return: int
 */
int _unsetenv(term_t term)
{
    char *str;
    size_t i;
    if (term.argv[1] != NULL)
    {
        str = _getenv(term.argv[1]);
        if (str != NULL)
        {
            for (i = 0; environ[i] != str; i++)
            ;
            for (; environ[i + 1] != NULL; i++)
            {
                environ[i] = environ[i + 1];
            }
            environ[i] = NULL;
        }
        return (0);
    }
    return (-1);
}
