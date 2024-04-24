#include "shell.h"

int execute(char **args, char **env)
{
	pid_t child_pid;
	int status;
	char *file_path;

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
			exit(EXIT_FAILURE);
		}
	}

	else if (child_pid < 0)
	{
		printf("erreur fork \n");
		free(file_path);
		return (-1);
	}
	else
	{
		/*process child is finish correctly*/
		waitpid(child_pid, &status, 0);

		if (WEXITSTATUS(status))
		{
			free(file_path);
			return WEXITSTATUS(status);
		}
		else
		{
			/*process child is finish anormale*/
			free(file_path);
			return (-1);
		}
	}

	return (0);
}
