#include "shell.h"

/**
*get_path - function that finds the full path of a given command
*@command: a ponter to pointer
*/

void get_path(char **command)
{
	int i;
	char **path_tokens = NULL;
	char *path = strdup(getenv("PATH"));
	char *temporary_path = NULL;

	path_tokens = split_string(path, ":");
	free(path);
	path = NULL;

	for (i = 0; path_tokens[i]; i++)
	{
	temporary_path = calloc(sizeof(char), (strlen(path_tokens[i]) + 1 + strlen(command[0]) + 1));
	strcat(temporary_path, path_tokens[i]);
	strcat(temporary_path, "/");
	strcat(temporary_path, command[0]);

	if (access(temporary_path, F_OK) == 0)
	break;
	free(temporary_path);
	temporary_path = NULL;
	}
	free_array(path_tokens);
	free(command[0]);
	command[0] = temporary_path;
}

