#include "shell.h"

/**
 * _strlen - checks the length of a string
 * @str: the string to check
 *
 * Return: the length of the string
 */

int _strlen(char *str)
{
int len = 0;

while (str[len] != '\0')
{
len++;
}
return (len);
}


/**
 * free_char_mem - frees a malloc'd buff
 * @buff: The buff to free
 *
 * Return: nothing
 */
void free_char_mem(char **buff)
{
size_t i;

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
s = malloc(sizeof(char) * (len + 1));
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


/**
 * _strcmp - compares two strings
 *
 * @s1: the first str,
 * @s2: the second str.
 *
 * Return: an int based on comparism.
 */
int _strcmp(char *s1, char *s2)
{
int i;
i = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] < s2[i])
{
return (s1[i] - s2[i]);
}
else if (s1[i] > s2[i])
return (s1[i] - s2[i]);
i++;
}
return (0);
}
