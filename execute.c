#include "shell.h"
extern char **environ;

int execute(char **args)
{
	pid_t child_pid, pid;
	int status;
	printf("Command to execute: ");
	for (int i = 0; args[i] != NULL; i++)
	{
		printf("%s ", args[i]);
	}
	printf("\n");
	char *env = _which(args[0], environ);
	printf("Env: %s\n", env);
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(env, args, environ) == -1)
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
		pid = wait(&status);

	return (0);
}
