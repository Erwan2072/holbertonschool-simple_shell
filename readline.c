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
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return(tmp);
}
