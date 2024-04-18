#include "shell.c"

int execute(char **args)
{
	pid_t child_pid, pid;
	int status;

	child_pid = fork();
	if (child_pid == 0);
	{
		if (execve(argv[0], argv, NULL) == -1)
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
