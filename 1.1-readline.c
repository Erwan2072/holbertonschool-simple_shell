#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *tmp =malloc(1024);
	size_t len = 2056;

	while(1)
	{
		printf("$ ");
		getline(&tmp, &len, stdin);
		printf("%s", tmp);
		break;
	}
	return (0);
}
