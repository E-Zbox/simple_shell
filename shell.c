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
ssize_t byts_read;
size_t len;
int status,  envs, is_term = isatty(0);
char *line, **argv;
signal(SIGINT, SIG_IGN);
(void)ac;
len = 0, line = NULL;
while (1)
{
if (is_term)
write(STDOUT_FILENO, "k_shell$ ", 9);
byts_read = getline(&line, &len, stdin);
if (byts_read == -1)
{
free(line);
exit(0);
}
argv = manage_line(line);
if (argv == NULL)
continue;
if (_strcmp(argv[0], "env") == 0)
{
print_env(env);
continue;
}
envs = check_env(argv[0]);
status = handle_path(envs, argv, av, env);
if (status == -1)
{
free(line);
exit(0);
}
execute(argv, av, env);
free_char_mem(argv);
}
free(line);
return (0);
}

/**
 * handle_path - handles the path directories
 * @argv: the cmd and arg array
 * @env_s: the user input status
 * @av: arg vector
 * @env:array of env vars
 *
 * Return: 0 on succes, -1 on error
 */
int handle_path(int env_s, char **argv, char **av, char **env)
{
char **path_dirs, *value, *path;
if (env_s == 1)
{
value = _getenv("PATH", env);
if (value == NULL)
{
cmd_error(av[0], argv[0]);
free_char_mem(argv);
return (-1);
}
path_dirs = break_path(value);
path = check_dir_permission(path_dirs, argv[0]);
if (path != NULL)
{
if (_strcmp("no access", path) == 0)
{
perm_error(av[0], argv[0]);
free_char_mem(argv);
free(path);
return (-1);
}
free(argv[0]);
argv[0] = path;
}
else
{
cmd_error(av[0], argv[0]);
free_char_mem(argv);
free(path);
return (-1);
}
}
return (0);
}
