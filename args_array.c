#include "shell.h"

/**
 * args_array - place the args (words) of a string in an array
 * @user_input: character string to process
 * Return: array of argument (words) of the input
 */
char **args_array(char *user_input)
{
	const char *str_entry = user_input;
	int count_mots = 0, i;
	char **mots;
	char *str_cpy = strdup(str_entry);
	char *j = strtok(str_cpy, " \n\t");

	while (j != NULL) /* compte le nombre de mot */
	{
		count_mots++;
		j = strtok(NULL, " \n\t");
	}

	mots = malloc((count_mots + 1) * sizeof(char *)); /* dimensionne tableau */

	free(str_entry);
	str_cpy = strdup(str_entry); /* réinitialise la copieChaine */

	j = strtok(str_cpy, " ");

	i = 0;
	while (j != NULL) /* place les mots dans le tableau */
	{
		mots[i] = strdup(j);
		i++;
		j = strtok(NULL, " ");
	}
	mots[i] = NULL; /* ajoute un mot NULL nécessaire pour execve */

	free(str_cpy);

	return (mots);
}