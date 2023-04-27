#include "shell.h"

/**
*free_array - a function that frees an array of strings
*@string_array : a pointer to pointer
*/

void free_array(char **string_array)
{
	int index;

	for (index = 0; string_array[index] != NULL; index++)
	{
	free(string_array[index]);
	string_array[index] = NULL;
	}

	free(string_array);
	string_array = NULL;
}

