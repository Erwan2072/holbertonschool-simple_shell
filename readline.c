#include "shell.h"

/**
 * readline - Read a line of input from stdin
 * Return: A pointer to the read line, or NULL on failure
 */

char *readline(void)
{
	char *tmp = NULL;
	size_t len = 0;

	if (getline(&tmp, &len, stdin) == -1)/* Read the line from stdin */
	{
		free(tmp);
		return (NULL);/*of error*/
	}
	if (strcmp(tmp, "exit\n") == 0)/* Check if the user entered "exit" to quit */
	{
		free(tmp);
		return (NULL);/*quit the program*/
	}

	return (tmp);/*Return the read line*/
}
void _print_env(char **env)
{
	int i = 0;

	while (env[i])
		printf("%s\n", env[i++]);
}
