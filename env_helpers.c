#include "shell.h"

/**
 * _getenv - gets env var
 *
 * @name: the name of the env var to get
 * @env: the env vars
 *
 * Return: a pointer to the env var value
 */
char *_getenv(char *name, char **env)
{
int i, len, compare = 1;
char *e_var, *token, *value;
i = 0;
len = _strlen(name);
while (env[i])
{
compare = _strcmp(env[i], name);
if ((compare == 0))
{
e_var = _strdup(env[i]);
if (_strlen(e_var) == (len + 1))
{
free(e_var);
return (NULL);
}
token = strtok(e_var, "=");
token = strtok(NULL, "=");
value = _strdup(token);
}
i++;
}
free(e_var);
return (value);
}

/**
 * check_env - checks if user enter path command
 * @cmd:  the command
 *
 * Return: 1 on true, 0 otherwise
 */
int check_env(char *cmd)
{
int compare1, compare2;
compare1 = _strcmp(cmd, "/");
compare2 = _strcmp(cmd, ".");
if (compare1 == 0 || compare2 == 0)
{
return (0);
}
return (1);
}


/**
 * print_env - prints current env bars
 * @env:  array of env vars
 *
 * Return: nothing
 */
void print_env(char **env)
{
int i = 0;
while (env[i])
{
write(STDOUT_FILENO, env[i], _strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}
