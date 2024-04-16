#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}
	// Get the value of the PATH environment variable
	char *path = getenv("PATH");
	if (path == NULL)
	{
		printf("Error: PATH environment variable not set.\n");
		return (1);
	}
	// Tokenize the PATH variable
	char *token = strtok(path, ":");
	while (token != NULL)
	{
		// Check each directory for the specified file
		for (int i = 1; i < argc; i++)
		{
			char filepath[1024];
			snprintf(filepath, sizeof(filepath), "%s/%s", token, argv[i]);
			// Check if the file exists and is executable
			if (access(filepath, F_OK | X_OK) == 0)
			{
				printf("%s\n", filepath);
			}
		}
		token = strtok(NULL, ":");
	}

	return (0);
}
