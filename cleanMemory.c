#include "header.h"

/**
 * cleanMemory - Frees dynamically allocated memory
 * for an input buffer and a word list.
 * @buffer: Pointer to the dynamically allocated input buffer.
 * @wordList: Pointer to the dynamically allocated array of words.
 */
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
