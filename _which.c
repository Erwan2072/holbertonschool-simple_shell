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
		return (cmd);

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
	free(filepath);
	free(token);
	free(copy_path);
	return (NULL);
}
