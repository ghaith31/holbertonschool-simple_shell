#include "shell.h"

/**
*get_path - function that finds the full path of a given command
*@command: a ponter to pointer
*/

void get_path(char **command)
{
	int i;
	char **tokn = NULL;
	char *path = strdup(getenv("PATH"));
	char *_path = NULL;

	tokn = split_string(path, ":");
	free(path);
	path = NULL;

	for (i = 0; tokn[i]; i++)
	{
	_path = calloc(sizeof(char), (strlen(tokn[i]) + 1 + strlen(command[0]) + 1));
	strcat(_path, tokn[i]);
	strcat(_path, "/");
	strcat(_path, command[0]);

	if (access(_path, F_OK) == 0)
	break;
	free(_path);
	_path = NULL;
	}
	free_array(tokn);
	free(command[0]);
	command[0] = _path;
}

