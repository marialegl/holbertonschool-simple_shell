#include "header.h"

void executeCommand(char **wordList)
{
	char *command;
	pid_t process = fork();

	if (process == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (process != 0)
	{
		int status;
		waitpid(process, &status, 0);
	}
	else
	{
		command = pathEnv(wordList[0]);

		if (command == NULL)
		{
			printf("bash: %s command not found\n", wordList[0]);
			exit(EXIT_SUCCESS);
		}

		if (strcmp("printenv", wordList[0])== 0 || strcmp("env", wordList[0]) == 0)
			printEnv();

		if (execve(command, wordList, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
}
