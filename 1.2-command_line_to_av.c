#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
        char *tmp =malloc(2056);
        size_t len = 2056;
	char *token;

        while(1)
        {
                printf("$ ");
                getline(&tmp, &len, stdin);
                printf("%s", tmp);
		token = strtok(tmp, " ");

		while (token != NULL)
		{
			printf(" %s\n", token);
			token = strtok(NULL , " ");
		}
	}
        return (0);
}
