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

	if (argc > 1)
	{
		/*Mode non interactif : arguments de ligne de commande fournis*/
		tmp = argv[0]; /*Utilisez le premier argument comme commande*/
		command = parsing_args(tmp);
		resultat = execute(command, env);
		free(command);
	}
	else
	{
		/*Mode interactif : pas d'arguments de ligne de commande*/
		while (1)
		{
			if (isatty(STDIN_FILENO))/*Vérifie si le prog est> mode interactif*/
				printf("$ "); /*Affiche le prompt*/
			tmp = readline();/*Lire la commande depuis stdin*/
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
			if (command != NULL)
                        {
                                free(command);
                                continue;
                        }
		}
	}
	return (resultat);
}
