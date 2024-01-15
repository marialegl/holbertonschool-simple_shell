#include "header.h"

/**
 * main - Entry point for the program.
 *
 * This function serves as the main execution point for the program.
 * It contains a loop that repeatedly prompts the user with ":) ", reads
 * their input, processes it, and continues until the user enters:
 * "exit" or "quit".
 *
 * Return: Always returns 0 to indicate successful completion.
 */
int main(void)
{
	int amountWords;
	char *buffer;
	char **wordList;
	int status = 0;

	while (status <= 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf(":) ");

		fflush(stdout);
		buffer = readInput();

		if (strcmp(buffer, "exit") == 0 || strcmp(buffer, "quit") == 0)
		{
			free(buffer);
			break;
		}
		if (strcmp(buffer, "env") == 0 || strcmp(buffer, "printenv") == 0)
		{
			printEnv();
			free(buffer);
			return (0);
		}

		wordList = tokenize(buffer, &amountWords);

		if (amountWords > 0)
			status = executeCommand(wordList);

		cleanMemory(buffer, wordList);
	}
	return (status);
}
