#include "header.h"

int main()
{
	int amount, i;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t read;
	char **wordList;
	char *command;

	while(1)
	{
		printf(":) ");
		read = getline(&buffer, &bufsize, stdin);

		if (read == -1)
		{
			perror("Error\n");
			break;
		}

		if (strcmp(buffer, "exit\n")== 0 || strcmp(buffer, "quit\n")== 0)
			break;


		wordList = tokenize(buffer, &amount);

		if (amount > 0)
		{
			pid_t process = fork();

			if (process == -1)
			{
				perror("Error");
				return (1);
			}

			if (process != 0)
			{
				int status;
				waitpid(process, &status, 0);
				continue;
			}

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
				 return (1);
			 }
		}

		for (i = 0; i<amount; i++)
			free(wordList[i]);

		free(wordList);
	}
	free(buffer);
	return (0);
}
