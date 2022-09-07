#include "shell.h"
/**
 * __realloc - my realloc function
 *
 * @args: parameter
 * @n: parameter
 * Return: char**
 */
char **__realloc(char **args, size_t n)
{
    char **sstr;
    size_t i = 0;
    sstr = malloc((n + 5) * sizeof(char *));
    if (sstr == NULL)
    {
        perror("Fatal Error");
        free(args);
        return (NULL);
    }
    for (i = 0; i < n; i++)
    {
        sstr[i] = args[i];
    }
    n += 5;
    free(args);
    return (sstr);
}
