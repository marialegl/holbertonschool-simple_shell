#include "header.h"

/**
 * tokenize - Tokenizes an input string into an array of words.
 *
 * @buffer: The input string to be tokenized.
 * @amountWords: Ptr to an int to store the word count.
 *
 * Return: Ptr to the dynamically allocated array of words.
 *         Must be freed by the caller.
 */
char **tokenize(const char *buffer, int *amountWords)
{
	char **wordList = NULL;
	char *token;
	char *bufferCopy = strdup(buffer);

	wordList = malloc(MAX_WORDS * sizeof(char *));

	if (wordList == NULL)
	{
		free(bufferCopy);
		perror("memory allocation failure");
		return (NULL);
	}

	token = strtok(bufferCopy, SEPARATOR);

	*amountWords = 0;

	while (token != NULL)
	{
		wordList[*amountWords] = strdup(token);
		(*amountWords)++;
		token = strtok(NULL, SEPARATOR);
	}

	wordList[*amountWords] = NULL;
	free(bufferCopy);
	return (wordList);
}
