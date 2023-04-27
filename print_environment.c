#include "shell.h"

/**
*print_environment - a function that prints the current environement
*/

void print_environment(void)
{
	char **envp = environ;

	for (; *envp; envp++)
	{
	printf("%s\n", *envp);
	}
}
