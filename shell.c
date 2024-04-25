#include "shell.h"
/**
 * main - Entry point of the program.
 *        Prompts the user for input and processes commands.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * @env: An array of strings containing the environment variables
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	char *tmp = NULL;
	char **command = NULL;
	int resultat = 0;
	(void) argc;
	(void) argv;

	if (isatty(STDIN_FILENO))/* Check if the stdin is a terminal */
		printf("$ ");/* Print symbol if so */

	
	while ((tmp = readline()) != NULL)/*Read user input until it's not NULL*/
	{
		if (isatty(STDIN_FILENO))/*Check if the standard input is a terminal*/
			printf("$ ");
		if (tmp == NULL)
		{
			printf("\n");
			break;/* Exit the while loop */
		}

		command = parsing_args(tmp);/*Parse the user input to get command arguments*/

		if (command == NULL)
		{
			free(tmp);
			continue;/*Move to the next iteration of the while loop*/
		}
		/* Execute the command with the given arguments */
		resultat = execute(command, argv[0], env);
		free(tmp);
		free(command);
	}
	return (resultat);
}
