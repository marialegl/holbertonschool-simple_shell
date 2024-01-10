#include "header.h"

void cleanMemory(char *buffer, char **wordList)
{
	int i;

	free(buffer);

        for (i = 0; wordList[i] != NULL; i++)
	{
		free(wordList[i]);
	}
	free(wordList);
}
