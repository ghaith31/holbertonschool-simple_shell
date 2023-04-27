#include "shell.h"

/**
*shell_loop - the main loop of the shell
*@input: an integer
*/

void shell_loop(int input)
{
	char *line = NULL, **tokens = NULL;
	size_t size = 0;
	ssize_t length;
	struct stat st;

	while (1)
	{
	if (input)
		write(STDOUT_FILENO, "$ ", 2);
	length = getline(&line, &size, stdin);
	if (length == EOF)
	{
		free(line);
		exit(0);
	}
	if (strcmp(line, "\n") == 0)
		continue;
	tokens = split_string(line, " \t\r\n");
	handle_exit_command(tokens, line);
	if (strcmp(tokens[0], "env") == 0)
	{
		print_environment();
		free_array(tokens);
		continue;
	}
	if (stat(tokens[0], &st) != 0)
		get_path(tokens);
	if (tokens[0] == NULL)
	{
		printf("Command not found\n");
		free(line);
		line = NULL;
		free_array(tokens);
		tokens = NULL;
		continue;
	}
	execute_command(tokens);
	free_array(tokens);
	}
	free(line);
}
