#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
	char *tmp = NULL;
	size_t len = 0;
	char *token;
	char *argv[64];
	int argc;

	while(1)
	{
		printf("#cisfun$ ");
		getline(&tmp, &len, stdin);
		char *token = strtok(tmp, " \n");
		printf("%s", token);
		while (token != NULL && argc < 63)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \n");
		}
		argv[argc] = NULL;
		execve(argv[0], argv, NULL);
	}
	return (0);
}
