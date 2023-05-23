#include "shell.h"

/**
 * parse_cmd - Parse Lines Of Input
i * @input: User Input To Parse
 *
 * Return: Array Of Char parsed
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int a, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtokn(input, "\n ");
	for (a = 0; token; a++)
	{
		tokens[a] = token;
		token = _strtokn(NULL, "\n ");
	}

	tokens[a] = NULL;
	return (tokens);
}
