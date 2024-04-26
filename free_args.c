#include "shell.h"
/**
 * free_args - Free strings in an array
 * @args: Array of pointer to free
 * Return: Nothing
 */
void free_args(char **args)
{
	int i;

	for(i = 0; args[i] != NULL; i++)
		free (args[i]);
	free(args);
}
