#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char **argv, char **env);
char **args_array(char *user_input);
char **parsing_args(char *line);
char *readline(void);
int execute(char **args,char *argv, char **env);
char *_which(char *cmd, char **env);
char *_getenv(const char *name, char **env);
void _print_env(char **env);
void free_args(char **argv);

#endif
