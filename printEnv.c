#include "header.h"

/**
 * printEnv - Prints the environment variables.
 *
 * This function prints the environment variables to the standard output.
 * It iterates through the environment variable array and prints each variable.
 * After printing, the function exits with a status of 0.
 */
void printEnv(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
