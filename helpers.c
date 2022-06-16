#include "shell.h"

/**
 * _strlen - checks the length of a string
 * @str: the string to check
 *
 * Return: the length of the string
 */

int _strlen(char *str)
{
int i;

i = 0;
while (str[i] != '\0')
{
i++;
}
return (i);
}


/**
 * free_char_mem - frees a malloc'd buff
 * @buff: The buff to free
 *
 * Return: nothing
 */
void free_char_mem(char **buff)
{
unsigned int i;

for (i = 0; buff[i]; i++)
{
free(buff[i]);
}
free(buff);
}

/**
 * _strdup - duplicates a string
 * @str: The str to duplicate
 *
 * Return: pointer to the new str
 */

char *_strdup(char *str)
{
int i, len;
char *s;
if (str == NULL)
{
return (NULL);
}
len = _strlen(str);
s = malloc(len + 1 * sizeof(char));
if (s == NULL)
{
return (NULL);
}
for (i = 0; i < len; i++)
{
s[i] = str[i];
}
s[i] = '\0';
return (s);
}
