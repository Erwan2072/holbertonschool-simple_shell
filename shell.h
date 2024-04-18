#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv);
char **args_betty(char *user_input);
char **parsing_args(char *line);
char readline(char *line);
int execute(char **args);

#endif
