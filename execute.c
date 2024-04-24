#include "shell.h"

int execute(char **args, char **env)
{
	pid_t child_pid;
	int status;
	char *file_path;

	/*for(i = 0; args[i] != NULL; i++)
	{
		printf("%s ", args[i]);
		}*/
	file_path = _which(args[0], env);
		if (file_path == NULL)
		{
			printf("No such file or directory\n");
			return (-1);
		}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(file_path, args, env) == -1)
		{
			printf("erreur exec \n");
			return (-1);
		}
	}
	else if (child_pid < 0)
	{
		printf("erreur fork \n");
		return (-1);
	}
	else
		wait(&status);

	return (0);
}
