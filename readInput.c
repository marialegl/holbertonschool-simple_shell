#include "header.h"

char *readInput()
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t read;

	read = getline(&buffer, &bufsize, stdin);

	if (read == -1)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}

	buffer[strcspn(buffer, "\n")] = '\0';

	return (buffer);
}
