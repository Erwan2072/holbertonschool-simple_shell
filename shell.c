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
	/*size_t len = 0;*/
	char **command = NULL;
	int resultat = 0;

	if (argc > 1)
	{
		/*Mode non interactif : arguments de ligne de commande fournis*/
		tmp = argv[0]; /*Utilisez le premier argument comme commande*/
		command = parsing_args(tmp);
		resultat = execute(command, env);
	}
	else
	{
		/*Mode interactif : pas d'arguments de ligne de commande*/
		while (1)
		{
			if (isatty(STDIN_FILENO))/*Vérifie si le prog est> mode interactif*/
				printf("$ "); /*Affiche le prompt*/
			tmp = readline();/*Lire la commande depuis stdin*/
			command = parsing_args(tmp);
			execute(command, env);
			free(tmp); /*Libérer la mémoire allouée par getline*/
			tmp = NULL; /*Réinitialiser tmp pour éviter les fuites de mémoire*/
		}
	}

	/*Libérer la mémoire*/
	free(command);

	return (resultat);
}
