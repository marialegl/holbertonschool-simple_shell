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
	char *copy = strdup(path);
	char *dir;

	if (copy == NULL)
	{
		perror("memory allocation failure");
		exit(EXIT_FAILURE);
	}

	dir = strtok(copy, ":");

	while (dir != NULL)
	{
		char *route = malloc(strlen(dir) + strlen(command) + 1);

		if (route == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		sprintf(route, "%s/%s", dir, command);

		if (access(route, X_OK) == 0)
			return (route);

		free(route);

		dir = strtok(NULL, ":");
	}
	free(copy);

	return (command);
}
