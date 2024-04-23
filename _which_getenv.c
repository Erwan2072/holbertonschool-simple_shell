#include "shell.h"
/**
 * _which - Find and print the full path of a given executable file in PATH
 * @cmd: Number of arguments
 * @env: Array of arguments
 * Return: 0 if file found, -1 otherwise
 */
char *_which(char *cmd, char **env)
{
        char *path = _getenv("PATH", env);
        char *filepath = NULL;
        char *copy_path = strdup(path);
        char *token = strtok(copy_path, ":");

        if (path == NULL)
        {
                printf("Error: PATH environment variable not set.\n");
                return (NULL);
        }

        if (copy_path == NULL)
        {
                perror("Memory allocation failed");
                return (NULL);
        }

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		return (cmd);
	}

        while (token != NULL)
        {
                filepath = malloc(strlen(token) + strlen(cmd) + 2);

                if (filepath == NULL)
                {
                        perror("Memory allocation failed");
                        free(copy_path);
                        return (NULL);
                }
		else
                        sprintf(filepath, "%s/%s", token, cmd);

		if (access(filepath, F_OK | X_OK) == 0)
                {
                        free(copy_path);
                        return (filepath);
                }
                free(filepath);
                token = strtok(NULL, ":");
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
