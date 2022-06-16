#include "shell.h"

/**
 * execute - executes a command
 * @argv: args vector
 * @av: the main program name
 * @env: an array of env vars
 * @path_dirs: array of dirs to be freed
 *
 * Return: 0 on success, -1 on error
 */

int execute(char **argv, char **av, char **env, char **path_dirs)
{
pid_t child_pid;
int status;
child_pid = fork();
if (child_pid < 0)
{
perror("Error");
return (-1);
}
if (child_pid == 0)
{
if (execve(argv[0], argv, env) == -1)
{
perror(av[0]);
return (-1);
}
free_char_mem(argv);
free_char_mem(path_dirs);
}
else
{
wait(&status);
}
return (0);
}


/**
 * break_cmd - breaks cmd into array of str
 * @command: the command to break
 *
 * Return: a pointer to the array
 */

char **break_cmd(char *command)
{
int i;
char **argv;
argv = malloc(sizeof(char *) * _strlen(command));
if (argv == NULL)
{
return (NULL);
}
argv[0] = _strdup(command);
argv[0] = strtok(argv[0], " ");
i = 0;
while (argv[i] != NULL)
{
i++;
argv[i] = strtok(NULL, " ");
}
argv[i] = NULL;
free(command);
return (argv);
}

/**
 * manage_line - set the line to an arr of cmd
 * @line: the imputed line
 *
 * Return: an array of str containing cmd
 */
char **manage_line(char *line)
{
char *ex, *cmd_buff;
char **argv;
int i, stop;
ex = "exit\n";
if (line[0] == '\n')
{
free(line);
exit(128);
}
for (i = 0; line[i]; i++)
{
if (line[i] == ex[i])
{
stop = 1;
}
else
{
stop = 0;
}
}
if (stop)
{
free(line);
exit(127);
}
cmd_buff = _strdup(line);
cmd_buff = strtok(cmd_buff, "\n");
argv = break_cmd(cmd_buff);
return (argv);
}
