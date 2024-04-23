#include "shell.h"
/**
 * _which - Find and print the full path of a given executable file in PATH
 * @cmd: Number of arguments
 * @env: Array of arguments
 * Return: 0 if file found, -1 otherwise
 */
char *_which(char *cmd, char **env)
{
	struct stat st;
	char *copy_path = _getenv("PATH", env), *token; /*find PATH in env*/
	char copy_cmd[150];

	if (copy_path != NULL)
		copy_path = _strdup(_getenv("PATH", env));
	/*check if it's an executable or absolute path*/
	if (cmd[0] == '/' || (cmd[0] == '.'))
	{
		if (stat(cmd, &st) == 0)
		{
			free(copy_path);
			return (_strdup(cmd));
		}
	}

	token = strtok(copy_path, ":");

	if (token != NULL)
	{
		do {
			_strncpy(copy_cmd, token); /* concatenate*/
			_strncat(copy_cmd, "/");
			_strncat(copy_cmd, cmd);

			if (stat(copy_cmd, &st) == 0)/* compare*/
			{
				free(copy_path);
				return (_strdup(copy_cmd)); /*return if exist*/
			}
			else
				copy_cmd[0] = 0;

			token = strtok(NULL, ":");
		} while (token != NULL);
	}
	free(copy_path);
	return (NULL);
}

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
