#include "shell.h"

int execute(char **args, char *program_name, char **env)
{
	pid_t child_pid;
	int status = 0;
	char *file_path;

	file_path = _which(args[0], env);
	if (file_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n",program_name , args[0]);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(file_path, args, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n",program_name , args[0]);
			printf(" \n");
			exit(127);
		}
	}

	else if (child_pid < 0)
	{
		perror("erreur fork");
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
