#include "shell.h"

/**
*split_string - a function that seperates command arguments
*@line: a ointer
*@delimiter: a pointer
*Return: value of tokens
*/

char **split_string(char *line, char *delimiter)
{
	char *token = NULL, **tokens = NULL;
	size_t i = 0;

	token = strtok(line, delimiter);
	while (token)
	{
	tokens = realloc(tokens, ((i + 1) * sizeof(char *)));
	tokens[i] = strdup(token);
	token = strtok(NULL, delimiter);
	i++;
	}

	tokens = realloc(tokens, ((i + 1) * sizeof(char *)));
	tokens[i] = NULL;

	return (tokens);
}

