#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

extern char **environ;
int _unsetenv(const char *name);

int main(void)
{
	putenv("MY_VARIABLE=123");
	putenv("OTHER_VARIABLE=456");
	printf("Before _unsetenv:\n");
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		++env;
	}
	_unsetenv("MY_VARIABLE");
	printf("\nAfter _unsetenv:\n");
	env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		++env;
	}
	return (0);
}
int _unsetenv(const char *name)
{
	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		return (-1);
	}
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
		{
			for (char **p = env; *p != NULL; ++p)
			{
				*p = *(p + 1);
			}
			return (0);
		}
		++env;
	}
	return (0);
}
