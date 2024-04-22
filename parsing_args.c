#include "shell.h"

char **parsing_args(char *line)
{
	int bufsize = 128, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " \n");
	}
	tokens[position] = NULL;
	return (tokens);
}
