#include "header.h"

/**
 * tokenize - Tokenizes an input string into an array of words.
 *
 * @inputString: The input string to be tokenized.
 * @amountWords: Ptr to an int to store the word count.
 *
 * Return: Ptr to the dynamically allocated array of words.
 *         Must be freed by the caller.
 */

char **tokenize(const char *inputString, int *amountWords)
{
	char **wordList = NULL;
	char *token;
	char *copy = strdup(inputString);

	wordList = malloc(MAX_WORDS * sizeof(char *));

	if (wordList == NULL)
	{
		free(copy);
		perror("memory allocation failure");
		exit(EXIT_FAILURE);
	}


	token = strtok(copy, SEPARATOR);

	*amountWords = 0;

	while (token != NULL)
	{
		wordList[*amountWords] = strdup(token);
		(*amountWords)++;
		token = strtok(NULL, SEPARATOR);
	}

	wordList[*amountWords] = NULL;
	free(copy);
	return (wordList);
}
