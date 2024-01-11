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
	char **wordList;
	char *token;
	char *copy = strdup(inputString);

	wordList = malloc(MAX_WORDS * sizeof(char *));

	if (wordList == NULL)
	{
		free(copy);
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, " \n");

	*amountWords = 0;

	while (token != NULL && *amountWords < MAX_WORDS)
	{
		wordList[*amountWords] = strdup(token);
		(*amountWords)++;
		token = strtok(NULL, " \n");
	}

	wordList[*amountWords] = NULL;
	free(copy);
	return (wordList);
}
