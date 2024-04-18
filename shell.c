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
	char *tmp = malloc(1024);
	size_t len = 1024;
	char **command;

	while (1)
	{
		printf("($) ");
		tmp = readline();
		command = parsing_args(tmp);
		printf("%s \n", tmp);
		execute(command);
	}
	free(tmp);
	free(command);
	return (0);
}
