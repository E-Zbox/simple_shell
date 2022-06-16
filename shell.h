#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
int _strlen(char *str);
char *_strdup(char *str);
char **alloc_char_mem(int len);
void free_char_mem(char **buff);
int _getline(char **av, char **env);
char **break_cmd(char *command);
int execute(char **argv, char **av, char **env, char **path_dirs);
int check_env(char *cmd);
char *_getenv(char *name, char **env);
char **break_path(char *path);
char *check_dir_permission(char **dir_arr, char *command);
char *concat_arg(char *path, char *cmd);
char **manage_line(char *line);
void cmd_error(char *name, char *cmd);
void perm_error(char *name, char *cmd);
#endif /* SHELL_H */
