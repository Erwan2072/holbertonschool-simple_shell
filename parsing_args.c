#include "shell.h"

/**
 * parsing_args - Function to parse a command line into tokens
 * @line: The command line to parse
 * Return: An array of strings (tokens) representing the command line arguments
 */

char **parsing_args(char *line)
{
	int bufsize = 128, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " \n");
	}
	if (position == 0)
	{
		tokens[position] = malloc(sizeof(char));
		if (!tokens[position])
		{
			fprintf(stderr, "allocation error\n");
			exit(EXIT_FAILURE);
		}
		tokens[position][0] = '\0';
		position++;
	}

	tokens[position] = NULL;
	return (tokens);
}
