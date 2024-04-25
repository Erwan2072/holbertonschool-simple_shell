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

	if (!tokens)/* Check if memory allocation succeeded */
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);/* Exit the program with an error code */
	}

	token = strtok(line, " \n");/*Split the line into tokens based on spaces and newlines*/
	while (token != NULL)
	{
		tokens[position] = token;/* Store the token in the arguments array */
		position++;
		token = strtok(NULL, " \n");/*next token */
	}
	if (position == 0)/* If no tokens were found */
	{
		tokens[position] = malloc(sizeof(char));/* Allocate memory for an empty token */
		if (!tokens[position])/* Check if allocation succeeded */
		{
			fprintf(stderr, "allocation error\n");
			exit(EXIT_FAILURE);
		}
		tokens[position][0] = '\0';/* Add a null character to terminate the string */
		position++;
	}

	tokens[position] = NULL;/* Add NULL at the end of the arguments array */
	return (tokens);
}
