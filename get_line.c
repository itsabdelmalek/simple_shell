#include "shell.h"

/**
* _getline - Reads the input by user
*
* Return: Input by user
*/
char *_getline()
{
int a, buffsize = BUFSIZE, rd;
char c = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (a = 0; c != EOF && c != '\n'; a++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[a] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (a >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[a] = '\0';
	hashtag_handle(buff);
	return (buff);
}

/**
 * hashtag_handle - remove everything after #
 * @buff: input
 *
 * Return:void
 */
void hashtag_handle(char *buff)
{
	int a;

		for (a = 0; buff[a] != '\0'; a++)
		{
			if (buff[a] == '#')
			{
			buff[a] = '\0';
			break;
			}
	}
}
