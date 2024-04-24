#include "shell.h"

int execute(char **args, char **env)
{
	pid_t child_pid;
	int status = 0;
	char *file_path;

	file_path = _which(args[0], env);
	if (file_path == NULL)
	{
		printf("%s: not found\n", args[0]);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(file_path, args, env) == -1)
		{
			printf("erreur exec \n");
			exit(127);
		}
	}

	else if (child_pid < 0)
	{
		printf("erreur fork \n");
		return (-1);
	}
	else
	{
		wait(&status);
		if ((WEXITSTATUS(status)) != 0)
			status = (WEXITSTATUS(status));
		return (status);
	}

	return (127);
}
