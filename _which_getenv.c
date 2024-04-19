#include "shell.h"
extern char **environ;

/**
 * _which - Find and print the full path of a given executable file in PATH
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 if file found, -1 otherwise
 */
char *_which(char *cmd, char **env)
{
	char *path = _getenv("PATH", environ);
	char *filepath = NULL;
	if (path == NULL)
	{
		printf("Error: PATH environment variable not set.\n");
		return (NULL); // Erreur si la variable d'environnement PATH n'est pas définie
	}

	// Tokenize the PATH variable
	char *token = strtok(path, ":");
	while (token != NULL)
	{
		// Check each directory for the specified file
		/*for (int i = 1; i < ; i++)*/
		{
			char *filepath = malloc(1024);
			sprintf(filepath, "%s/%s", token, cmd);
			printf("Before check if exist :%s\n", filepath);
			// Check if the file exists and is executable
			if (access(filepath, F_OK | X_OK) == 0)
			{
				printf("%s\n", filepath);
				return (filepath); // Fichier trouvé, retourne 0
			}
		}
		token = strtok(NULL, ":");
	}
	free(filepath);
	return (NULL); // Fichier non trouvé, retourne -1
}

/**
 * _getenv - Find the environment variable
 * @name: Environment variable name
 * @env: Array of environment variables
 * Return: Pointer to the content of the environment variable, NULL if not found
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
                return (env[i] + j + 1); // Retourne le contenu de la variable d'environnement
            }
            else
                break;
        }
    }
    return (NULL); // Variable d'environnement non trouvée, retourne NULL
}
