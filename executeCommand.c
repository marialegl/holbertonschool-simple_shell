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
 * Return: Always returns 0 to indicate successful completion.
 */
int executeCommand(char **wordList)
{
	struct stat st;
	char *command;
	pid_t process;

	command = pathEnv(wordList[0]);

	if (command == NULL || stat(command, &st) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", wordList[0]);
		return (127);
	}

	if (command != wordList[0])
	{
		free(wordList[0]);
		wordList[0] = command;
	}

	process = fork();
	if (process == -1)
	{
		return (1);
	}

	if (process != 0)
	{
		int status;

		waitpid(process, &status, 0);
		if (status != 0)
			return (2);

		return (0);
	}

	if (execve(command, wordList, NULL) == -1)
		return (1);

	return (0);
}
