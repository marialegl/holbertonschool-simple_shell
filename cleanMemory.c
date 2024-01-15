#include "header.h"

/**
 * cleanMemory - Frees the allocated memory for buffer and wordList.
 *
 * @buffer: Pointer to the dynamically allocated input buffer.
 * @wordList: Pointer to the dynamically allocated array of words.
 *
 * This function frees the memory allocated for the input buffer and the array
 * of words.
 * It iterates through the wordList and frees each word before freeing
 * the entire array.
 */

void cleanMemory(char *buffer, char **wordList)
{
	int i;

	for (i = 0; wordList[i] != NULL; i++)
	{
		free(wordList[i]);
		wordList[i] = NULL; /* TO TEST */
	}
	free(wordList);
	free(buffer);
}
