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

	if (isatty(STDIN_FILENO))
		printf("$ ");

	/*Mode interactif : pas d'arguments de ligne de commande*/
	while ((tmp = readline()) != NULL)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (tmp == NULL)
		{
			printf("\n");
			break;
		}

		command = parsing_args(tmp);

		if (command == NULL)
		{
			free(tmp);
			continue;
		}
		resultat = execute(command, env);
		free(tmp);
		free(command);
	}
	return (resultat);
}
