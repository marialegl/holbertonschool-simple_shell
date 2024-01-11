#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite);

int main(void)
{
	_setenv("EXAMPLE_VAR", "example_value", 1);
	printf("EXAMPLE_VAR=%s\n", getenv("EXAMPLE_VAR"));
	_setenv("EXAMPLE_VAR", "new_value", 0);
	printf("EXAMPLE_VAR=%s\n", getenv("EXAMPLE_VAR"));
	_setenv("NEW_VAR", "new_variable", 1);
	printf("NEW_VAR=%s\n", getenv("NEW_VAR"));
	return (0);
}
int _setenv(const char *name, const char *value, int overwrite)
{
	int i;
	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			if (!overwrite)
			{
				return (0);
			}
			free(environ[i]);
			break;
		}
	}
	size_t len = strlen(name) + strlen(value) + 2;
	char *newEnvVar = malloc(len);

	if (newEnvVar == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}
	snprintf(newEnvVar, len, "%s=%s", name, value);
	int envCount;

	for (envCount = 0; environ[envCount] != NULL; ++envCount) 
	{}
	char **newEnviron = malloc((envCount + 2) * sizeof(char *));
	if (newEnviron == NULL)
	{
		perror("Memory allocation error");
		free(newEnvVar);
		return (1);
	}
	for (int j = 0; j < envCount; ++j)
	{
		newEnviron[j] = environ[j];
	}
	newEnviron[envCount] = newEnvVar;
	newEnviron[envCount + 1] = NULL;
	environ = newEnviron;
	return (0);
}
