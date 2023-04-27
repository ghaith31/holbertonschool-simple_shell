#include "shell.h"

/**
*execute_command - a function that executes a command
*@command: a pointer to pointer
*/

void execute_command(char **command)
{
	pid_t pid = 0;
	int status = 0;

	if (command != NULL)
	{
	pid = fork();
	if (pid == -1)
	{
	printf("Error in Fork\n");
	}
	else if (pid > 0)
	{
	waitpid(pid, &status, 0);
	}
	else if (pid == 0)
	{
	if (execve(command[0], command, environ) == -1)
	{
		printf("%s: not found", command[0]);
	}
	}
	}
}
