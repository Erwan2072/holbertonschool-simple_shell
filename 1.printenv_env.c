#include <stdio.h>
// Declaration of the global variable 'environ'
extern char **environ;

int main (int argc, char *argv[], char *env[])
{
	// Print the addresses of env and environ
	printf("Address of env: %p\n", env);
	printf("Address of environ: %p\n", environ);

	// Check if env and environ point to the same memory location
	if (env == environ)
	{
		printf("env and environ point to the same memory location.\n");
	}
	else
	{
		printf("env and environ do not point to the same memory location.\n");
	}

	return (0);
}
