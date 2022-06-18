#include "shell.h"

/**
 * break_path - breaks the path env into an array of strings
 * @path: the path env var;
 *
 * Return: the dirs in the path
 */

char **break_path(char *path)
{
char **token;
int i, p_len;
i = 0;
if (!path)
{
return (NULL);
}
p_len = _strlen(path);
token = malloc(sizeof(char *) * p_len);
if (token == NULL)
return (NULL);
token[0] = strtok(path, ":");
while (token[i])
{
i++;
token[i] = strtok(NULL, ":");
}
return (token);
}


/**
 * concat_arg - concats path with command
 * @path: the path arg
 * @cmd: the command to add
 *
 * Return: a pointer to the buff
 */
char *concat_arg(char *path, char *cmd)
{
int i, j, total_len;
char *path_buff;
i = 0;
total_len = _strlen(path) + _strlen(cmd);
path_buff = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
if (path_buff == NULL)
return (NULL);
while (path[i])
{
path_buff[i] = path[i];
i++;
}
path_buff[i] = '/';
i += 1;
for (j = 0; cmd[j]; j++, i++)
{
path_buff[i] = cmd[j];
}
path_buff[total_len + 1] = '\0';
return (path_buff);
}


/**
 * check_dir_permission - checks if a dir exists and contain a file
 * @dir_arr: an arr of dir to check
 * @command: the file to look for
 *
 * Return: the path if found, null on error
 */
char *check_dir_permission(char **dir_arr, char *command)
{
char *path_buf;
int i, ok_f = 0, ok_x = 0;

for (i = 0; dir_arr[i]; i++)
{
path_buf = concat_arg(dir_arr[i], command);
ok_f = access(path_buf, F_OK);
ok_x = access(path_buf, X_OK);
if (ok_f == 0)
{
if (ok_x == 0)
{
return (path_buf);
}
}
}
free(path_buf);
return (NULL);
}
