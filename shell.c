#include "shell.h"

/**
 * main - Entry point of the program.
 *        Prompts the user for input and processes commands.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
    char *tmp = NULL;
    size_t len = 0;
    char **command = NULL;

    if (argc > 1)
    {
        // Mode non interactif : arguments de ligne de commande fournis
        tmp = argv[1]; // Utilisez le premier argument comme commande
        command = parsing_args(tmp);
        execute(command);
    }
    else
    {
        // Mode interactif : pas d'arguments de ligne de commande
        while (1)
        {
            if (isatty(STDIN_FILENO)) // Vérifie si le programme est en mode interactif
                printf("($) "); // Affiche le prompt
            getline(&tmp, &len, stdin); // Lire la commande depuis l'entrée standard
            command = parsing_args(tmp);
            execute(command);
            free(tmp); // Libérer la mémoire allouée par getline
            tmp = NULL; // Réinitialiser tmp pour éviter les fuites de mémoire
        }
    }

    // Libérer la mémoire
    free(tmp);
    free(command);

    return 0;
}