#include <stdio.h>
#include <string.h>

char **environ;  // Declaration of environ
char *_getenv(const char *name);

int main()
{
	char *environmentVariableName = "MY_ENV_VARIABLE";
	char *variableValue = _getenv(environmentVariableName);
	
	if (variableValue != NULL)
	{
		printf("Value of %s: %s\n", environmentVariableName, variableValue);
	}
	else
	{
		printf("%s not found in the environment.\n", environmentVariableName);
	}
	return 0;
}

char *_getenv(const char *name)
{
	if (name == NULL || environ == NULL)
	{
		return NULL;
	}
	size_t name_length = strlen(name);

	for (char **env_var = environ; *env_var != NULL; ++env_var)
	{
		if (strncmp(*env_var, name, name_length) == 0 && (*env_var)[name_length] == '=')
		{
			return *env_var + name_length + 1;
		}
	}
	return NULL;
}
