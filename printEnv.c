#include "header.h"

void printEnv(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	exit(0);
}
