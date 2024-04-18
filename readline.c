#include "shell.h"

char readline(char *line)
{
    char *tmp = NULL;
	size_t len = 0;

	while(1)
	{
		if (getline(&tmp, &len, stdin) == -1)
            if (feof(stdin)) /*la fin du fichier d'entrée a été atteinte (EOF - End Of File)*/
                exit(EXIT_SUCCESS);/*we recieved an EOF*/
        else 
        {
            perror("readline");
            exit (EXIT_FAILURE);
        }
	    return(line);
    }
}