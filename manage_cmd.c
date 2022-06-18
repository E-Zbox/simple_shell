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
char **argv;
argv = malloc(sizeof(char *) * _strlen(command) + 1);
if (argv == NULL)
{
free(command);
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
free(command);
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
if (line[0] == '\n')
{
free(line);
return (NULL);
}
stop = _strcmp(ex, line);
if (stop == 0)
{
free(line);
exit(127);
}
cmd_buff = _strdup(line);
cmd_buff = strtok(cmd_buff, "\n");
argv = break_cmd(cmd_buff);
free(line);
return (argv);
}
