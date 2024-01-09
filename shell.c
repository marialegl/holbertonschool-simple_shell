#include "header.h"

int main()
{
	int amount;
	char *buffer;
	char **wordList;

	while(1)
	{
		printf(":) ");
		fflush(stdout);

		buffer = readInput();


		if (strcmp(buffer, "exit")== 0 || strcmp(buffer, "quit")== 0)
			break;


		wordList = tokenize(buffer, &amount);

		if (amount > 0)
			executeCommand(wordList);
	
		cleanMemory(buffer, wordList);
	}
	return (0);
}
