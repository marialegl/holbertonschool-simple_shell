#include "header.h"


/**
 * pathEnv - Resolves the full path of a command using the PATH environment
 * variable.
 *
 * @command: The command for which to resolve the full path.
 *
 * Return: The full path of the command if found in PATH
 * or the original command
 * if not found or in case of memory allocation failure.
 */
char *pathEnv(char *command)
{
	char *path = _getenv("PATH");
	char *dir, *pathCopy, *route = NULL;

	if (path == NULL || *path == '\0')
	{
		if (access(command, X_OK) == 0)
			return (command);
		else
			return (NULL);
	}
	pathCopy = strdup(path);

	if (pathCopy == NULL)
		return (NULL);

	dir = strtok(pathCopy, ":");

	while (dir != NULL)
	{
		size_t routeLen = strlen(dir) + strlen(command) + 2;

		route = malloc(routeLen);

		if (route == NULL)
		{
			free(pathCopy);
			return (NULL);
		}
		sprintf(route, "%s/%s", dir, command);

		if (access(route, X_OK) == 0)
		{
			free(pathCopy);
			return (route);
		}
		free(route);
		dir = strtok(NULL, ":");
	}
	free(pathCopy);
	return (command);
}
