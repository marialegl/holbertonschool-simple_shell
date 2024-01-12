#include "header.h"


/**
 * executeCommand - Executes a command with the given list of words.
 * @wordList: Pointer to the array of words representing the command.
 *
 * This function executes a command with the given list of words. It uses fork
 * to create a new process for the command execution. The parent process waits
 * for the child process to complete.
 * The child process handles command execution,
 * including checking if the command exists and handling built-in commands.
 *
 */
void executeCommand(char **wordList)
{
	struct stat st;
	char *command;
	pid_t process;

	command = pathEnv(wordList[0]);

	if (stat(command, &st) != 0)
	{
		fprintf(stderr, "bash: %s command not found\n", wordList[0]);
		free(command);
		return;
	}

	process = fork();

	if (process == -1)
	{
		perror("bash: fork");
		free(command);
		return;
	}

	if (process != 0)
	{
		int status;

		waitpid(process, &status, 0);
		free(command);

		if (status != 0)
		{
			exit(2);
		}
		return;
	}

	/*if (strcmp("printenv", wordList[0]) == 0 || strcmp("env", wordList[0]) == 0)
	{
		printEnv();
		free(command);
	}*/
	if (execve(command, wordList, environ) == -1)
	{
		perror("bash: execve");
		free(command);
		exit(EXIT_FAILURE);
	}
	free(command);
}
