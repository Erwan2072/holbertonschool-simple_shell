#include "shell.h"

char *readline(void)
{
	char *tmp = NULL;
	size_t len = 0;

	if (getline(&tmp, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);/*we recieved an EOF*/
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(tmp, "exit\n") == 0)
		{
			free(tmp);
			exit(EXIT_SUCCESS);
		}
	return(tmp);
}
