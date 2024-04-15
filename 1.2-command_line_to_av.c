#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        char *tmp =malloc(1024);
        size_t len = 2056;
	char *token;

        while(1)
        {
                printf("$ ");
                getline(&tmp, &len, stdin);
                printf("%s", tmp);
		token = strtok(tmp, " ");
        }
	while (token != NULL)
	{
		printf( " %s\n", token);
		token = strtok(NULL , " ");
	}
        return (0);
}
