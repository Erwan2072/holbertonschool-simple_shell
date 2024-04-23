#include "shell.h"

/**
 * execute - command executor
 * @cmd_t: =1 if args[0] is a executable©, 0otherwise
 * @args: An array of char str the arguments of the command to be executed
 * @env: An array of str the environment in which the command is to be executed
 * @cmd_count: counter of the number of times a command has been executed
 * @av: - function name, e.g. ./hsh
 *Return: always 0
 */
int execute(int cmd_t, char **args, char **env, int cmd_count, char *av)
{
	pid_t child_pid;
	int status;

	if (cmd_t == NULL)/*if no executable found*/
	{
		printf(strerr, "%s: not found\n", av, cmd_count, args[0]);
		return (127);
	}
	else
	{
		child_pid = fork();/*creation process child */

		/* if child process creation fails */
		if (child_pid == -1)
		{
			perror("fork");
			return (-1);
		}
		/*child process*/
		if (child_pid == 0)
		{
			/* Exec cmd with arguments, then if successful, close the process */
			if (execve(args[0], args, env) == -1)
			{
				/*If Exec fails, prints msg err and closes child process */
				printf(stderr, "%s: %d: %s: not found\n", av, cmd_count, args[0]);
				exit(127);
			}
		}
		/*parent process */
		else if (child_pid > 0)
		{
			wait(&status);/*Waits for end of child process and recovers process status*/
			if ((WEXITSTATUS(status)) != 0)/*if child process status not null */
				status = (WEXITSTATUS(status)); /*retrieve child process status */
			return (status);
		}
	}
	printf(stderr, "%s: %d: %s: not found\n", av, cmd_count, args[0]);
	return (127);
}
