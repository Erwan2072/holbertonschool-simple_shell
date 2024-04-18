#include "shell.h"

int execute(char **args)
{
	pid_t child_pid, pid;
	int status;

	child_pid = fork();
	if (child_pid == 0);
	{
		if (execve(args[0], args, NULL) == -1)
		{
			printf("erreur");
			exit(-1);
		}
		else if (child_pid < 0)
			printf("erreur");
		else
			pid = wait(&status);
	}
	return(1);
}
