#include "shell.h"

/**
 * readline - Read a line of input from stdin
 * Return: A pointer to the read line, or NULL on failure
 */

char *readline(void)
{
	char *tmp = NULL;
	size_t len = 0;

	if (getline(&tmp, &len, stdin) == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (strcmp(tmp, "exit\n") == 0)
	{
		free(tmp);
		exit(EXIT_SUCCESS);
	}
	return (tmp);
}
