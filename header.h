#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_WORDS 100

extern char **environ;

char** tokenize(const char* inputString, int* amountWords);
void printEnv();
char *pathEnv(char *command);
int main();

#endif
