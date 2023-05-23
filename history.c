#include "shell.h"

/**
 * history - fills the files by the inputs of the user
 * @input: User Input
 * @output: on success
 *
 * Return: On success, returns 1. On failure, returns -1.
 */

int history(char *input)
{
	char *filename = ".the_simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_env - Free Enviroment Variable Array
 * @env:  Environment variables
 *
 * Return: Void no return
 */
void free_env(char **env)
{
	int a;

	for (a = 0; env[a]; a++)
	{
		free(env[a]);
	}
}
