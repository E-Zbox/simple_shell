#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void free_char_mem(char **buff);
int _getline(char **av, char **env);
int handle_path(int env_s, char **argv, char **av, char **env);
char **break_cmd(char *command);
int execute(char **argv, char **av, char **env);
int check_env(char *cmd);
char *_getenv(char *name, char **env);
void print_env(char **env);
char **break_path(char *path);
int get_path_count(char *path);
char *check_dir_permission(char **dir_arr, char *command);
char *concat_arg(char *path, char *cmd);
char **manage_line(char *line);
int get_cmd_len(char *cmd);
void cmd_error(char *name, char *cmd);
void perm_error(char *name, char *cmd);
#endif /* SHELL_H */
