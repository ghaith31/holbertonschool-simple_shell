#include "shell.h"

/**
*main- the main function
*Return: (0)
*/

int main(void)
{
	shell_loop(isatty(STDIN_FILENO));

	return (0);
}
