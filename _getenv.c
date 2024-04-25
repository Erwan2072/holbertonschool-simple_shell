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
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (&(env[i][len + 1]));
		}
	}
	return (NULL); /* Variable d'environnement non trouvée */
}
