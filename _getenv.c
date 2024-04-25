#include "shell.h"

/**
 * _getenv - Find the environment variable
 * @name: Environment variable name
 * @env: Array of environment variables
 * Return: Pointer to the content of the env variable, NULL if not found
 */
char *_getenv(const char *name, char **env)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		/* Check if the variable matches the name */
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (&(env[i][len + 1]));/*Return the value of the variable*/
		}
	}
	return (NULL); /* Return NULL if the variable is not found */
}
