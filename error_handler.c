#include "shell.h"

/**
 * cmd_error - prints error when cmd not found
 * @name: the name of the program
 * @cmd: the command not found
 * Return: nothing
 */
void cmd_error(char *name, char *cmd)
{
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "1: ", 3);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * perm_error - prints error when user does not have perm
 * @name: the name of the program
 * @cmd: the command not granted
 *
 * Return: nothing
 */
void perm_error(char *name, char *cmd)
{
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, ": Permission denied\n", 20);
}
