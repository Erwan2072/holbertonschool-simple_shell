#include "shell.h"

/**
 * _getenv - Find the environment variable
 * @name: Environment variable name
 * @env: Array of environment variables
 * Return: Pointer to the content of the env variable, NULL if not found
 */
char *_getenv(const char *name, char **env)
{
	int i, j;

	for (i = 0; env[i]; i++)
	{
		for (j = 0; env[i][j]; j++)
		{
			if (env[i][j] == name[j])
				continue;
			else if (env[i][j] == '=' && name[j] == '\0')
			{
				return (env[i] + j + 1);/*Return cont var env */
			}
			else
				break;
		}
	}
	return (NULL); /*Variable d'environnement non trouvée, retourne NULL*/
}

