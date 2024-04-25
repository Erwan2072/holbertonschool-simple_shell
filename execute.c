#include "shell.h"
/**
 * execute - Execute a program with arguments
 * @args: Array of arguments for the program
 * @program_name: Name of the program executing the command
 * @env: Array of environment variables
 * Return: Exit status of the executed program
 */
int execute(char **args, char *program_name, char **env)
{
pid_t child_pid;
int status = 0;
char *file_path;

file_path = _which(args[0], env);
if (file_path == NULL)
{
	fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
	return (127);/*return error code*/
}

child_pid = fork();/* creation process child */
if (child_pid == 0)/* child process */
{
	/* Exec cmd with arguments then, if it fails, close the process */
	if (execve(file_path, args, env) == -1)
	{
		/* If Exec fails, prints msg err and closes child process */
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		exit(127);
	}
}
/* parent process */
else if (child_pid < 0)
{
	perror("erreur fork");
	return (-1);
}
else
{
	wait(&status);/*Waits for end of child process and recovers process st*/
	if ((WEXITSTATUS(status)) != 0)/* if child process status not null */
		status = (WEXITSTATUS(status));/*retrieve child process status*/
	return (status);
}

return (127);
}
