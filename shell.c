#include "shell.h"

/**
 * main - creates a simple shell
 * @av: arg count
 * @ac: arg vector
 * @env: an arr of env variables
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
int  status, is_term = isatty(0);
(void)ac;
signal(SIGINT, SIG_IGN);

while (1)
{
if (is_term)
write(STDOUT_FILENO, "k_shell$ ", 9);
status = _getline(av, env);
if (status < 0)
continue;
}
return (0);
}

/**
 * _getline - get a line from stdin and set it to a command
 * @av: the arg vector
 * @env: the env variables
 *
 * Return: 0 on succes, -1 on error
 */
int _getline(char **av, char **env)
{
int envs, exec_stat;
ssize_t byts_read;
size_t len;
char *line, **argv, **path_dirs, *value, *path;
int exitcode = 0;
len = 0, line = NULL;
byts_read = getline(&line, &len, stdin);
if (byts_read == -1)
{
free(line);
exit(exitcode);
}
argv = manage_line(line);
if (argv == NULL)
return (-1);
envs = check_env(argv[0]);
value = _getenv("PATH", env);
path_dirs = break_path(value);
path = check_dir_permission(path_dirs, argv[0]);
if (envs)
{
if (path != NULL)
{
argv[0] = path;
}
else
{
cmd_error(av[0], argv[0]);
free_char_mem(argv);
free(value);
exitcode = 126;
exit(exitcode);
}
}
exec_stat = execute(argv, av, env);
free(value);
free(path);
return (exec_stat);
}
