#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_WORDS 1024
#define SEPARATOR " \n\t"

extern char **environ;
char *readInput(void);
char **tokenize(const char *buffer, int *amountWords);
void printEnv(void);
char *pathEnv(char *command);
int executeCommand(char **wordList);
void cleanMemory(char *buffer, char **wordList);
char *_getenv(const char *name);

#endif
