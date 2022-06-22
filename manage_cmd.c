#include "shell.h"

/**
 * execute - executes a command
 * @argv: args vector
 * @av: the main program name
 * @env: an array of env vars
 *
 * Return: 0 on success, -1 on error
 */

int execute(char **argv, char **av, char **env)
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
char *token;
char **argv;
argv = malloc(sizeof(char *) * _strlen(command) + 1);
if (argv == NULL)
{
return (NULL);
}
token = strtok(command, " ");
argv[0] = _strdup(token);
i = 0;
while (argv[i] != NULL)
{
i++;
token = strtok(NULL, " ");
argv[i] = _strdup(token);
}
argv[i] = NULL;
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
int stop;
ex = "exit";
if (line[0] == '\n' || line[0] == ' ')
{
return (NULL);
}
stop = _strcmp(ex, line);
if (stop == 0)
{
free(line);
exit(0);
}
cmd_buff = strtok(line, "\n");
argv = break_cmd(cmd_buff);
if (_strcmp("env", cmd_buff) == 0)
{
argv[0] = "env";
}
return (argv);
}

/**
 * get_cmd_len - count the len of cmd
 * @cmd: the imputed command
 *
 * Return: the length of command
 */
int get_cmd_len(char *cmd)
{
int count, i = 0;
while (cmd[i])
{
if (cmd[i] != ' ')
{
count++;
}
i++;
}
return (count);
}
