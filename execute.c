#include "shell.h"

/**
 * execute - command executor
 * @args: An array of char str the arguments of the command to be executed
 * @env: An array of str the environment in which the command is to be executed
 *Return: always 0
 */
int execute(char **args, char **env)
{
	pid_t child_pid;
	int status;
	char *file_path;

	file_path = _which(args[0], env);
		if (file_path == NULL)
		{
			printf("%s: not found\n", args[0]);
			return (-1);
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
		{
			wait(&status);/*Waits for end of child process and recovers process status*/
			if ((WEXITSTATUS(status)) != 0)/*if child process status not null */
				status = (WEXITSTATUS(status)); /*retrieve child process status */
			return (status);
		}
	}
	return (127);
}
