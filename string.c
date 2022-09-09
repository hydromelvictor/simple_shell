#include "shell.h"
/**
 * _strdup - copy
 *
 * @src: parameter
 * Return: char*
 */
char *_strdup(const char *src)
{
size_t i;
char *dest;
if (src != NULL)
{
dest = malloc(strlen(src) * sizeof(char) + 1);
if (dest == NULL)
{
return (NULL);
}
for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
return (dest);
}
return (NULL);
}

/**
 * _strcat - concatenation
 *
 * @dest: parameter
 * @src: parameter
 * Return: char*
 */
char *_strcat(char *dest, char *src)
{
size_t i, j, k, l;
char *str;
if (dest != NULL)
{
if (src != NULL)
{
for (i = 0; dest[i]; i++)
;
for (j = 0; src[j]; j++)
;
str = malloc((i + j) * sizeof(char));
if (str == NULL)
{
return (NULL);
}
for (k = 0; k < i; k++)
{
str[k] = dest[k];
}
for (l = 0; l < j; l++)
{
str[k + l] = src[l];
}
return (str);
}
return (dest);
}
return (NULL);
}
