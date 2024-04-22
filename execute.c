#include "shell.h"

int execute(char **args, char **env)
{
	pid_t child_pid;
	int status, i;
	char *file_path;

	printf("Command to execute: ");
	for(i = 0; args[i] != NULL; i++)
	{
		printf("%s ", args[i]);
	}
	printf("\n");
	file_path = _which(args[0], env);
		if (file_path == NULL)
		{
			printf("error file_path , NULL")
			return (-1);
		}
	printf("file_path: %s\n", file_path);
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(file_path, args, env) == -1)
		{
			printf("erreur exec \n");
			exit(-1);
		}
	}
	else if (child_pid < 0)
	{
		printf("erreur fork \n");
		return(-1);
	}
	else
		wait(&status);

	return (0);
}
