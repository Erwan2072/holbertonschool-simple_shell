#include "shell.h"
/**
 * _which - Find and print the full path of a given executable file in PATH
 * @cmd: Number of arguments
 * @env: Array of arguments
 * Return: 0 if file found, NULL otherwise
 */
char *_which(char *cmd, char **env)
{
	char *path = _getenv("PATH", env), *filepath = NULL;
	char *copy_path = strdup(path), *token = strtok(copy_path, ":");

	if (path == NULL)
	{
		printf("Error: PATH environment variable not set.\n");
		free(copy_path);
		return (NULL);
	}
	if (copy_path == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	if (cmd[0] == '/' || cmd[0] == '.')/* check if cmd is executable*/
	{
		free(copy_path);
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
			sprintf(filepath, "%s/%s", token, cmd);/* concatene token and cmd*/
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
