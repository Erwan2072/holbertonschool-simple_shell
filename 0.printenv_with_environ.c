#include <stdio.h>
#include <stdlib.h>

int main() 
{
	extern char **environ; // Déclaration de la variable globale environ
	char **env_ptr = environ; // Pointeur vers le tableau de chaînes de caractères

	// Parcourir le tableau de chaînes de caractères jusqu'à la fin (NULL)
	while (*env_ptr != NULL) 
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}

    return 0;
}
