#ifdef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv);
char **args_betty(char *user_input);

#endif