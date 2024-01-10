#include "header.h"

char *pathEnv(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		char *route = malloc(strlen(dir) + strlen(command) + 2);

		if (route == NULL)
			return (NULL);

		sprintf(route, "%s/%s", dir, command);

		if (access(route, X_OK) == 0)
			return (route);

		free(route);

		dir = strtok(NULL, ":");
	}
	return (command);
}
