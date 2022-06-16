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
int i, j, len, v_len;
char *value, *e_var;
i = 0;
len = _strlen(name);
while (env[i])
{
v_len = _strlen(env[i]);
e_var = malloc(sizeof(char) * len);
if (e_var == NULL)
return (NULL);
for (j = 0; v_len > 0; j++, v_len--)
{
if (env[i][j] == name[j])
{
e_var[j] = env[i][j];
}
}
if (_strlen(e_var) == len)
{
free(e_var);
e_var = env[i];
break;
}
i++;
}
value = malloc(sizeof(char) * (_strlen(e_var) - (len - 1)));
if (value == NULL)
return (NULL);
i = 0;
len += 1;
while (e_var[i])
{
value[i] = e_var[len];
len++;
i++;
}
return (value);
}

/**
 * check_env - checks if user enter env arg
 * @cmd:  the command
 *
 * Return: 1 on true, 0 otherwise
 */
int check_env(char *cmd)
{
char *command;
int i, envs = 1;
command = "/";
for (i = 0; command[i]; i++)
{
if (command[i] == cmd[i])
{
envs = 0;
}
if (i == _strlen(cmd))
{
break;
}
}
return (envs);
}
