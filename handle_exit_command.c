#include "shell.h"

/**
*handle_exit_command - a function that handles the exit command
*@cmd: a pointer to pointer
*@line: a pointer
*/

void handle_exit_command(char **cmd, char *line)
{

	if (strcmp(cmd[0], "exit") == 0)
	{
	free(line);
	if (cmd[1])
	exit(atoi(cmd[1]));
	free_array(cmd);
	exit(0);
	}
}
