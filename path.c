#include "shell.h"

/**
 * path_cmd -  Search in the path For Excutable Command
 * @cmd: Parsed Input
 *
 * Return: 0 on Success 1 if failed.
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buff;

	path = _getenv("PATH");
	value = _strtokn(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buff) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtokn(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * build - Build Command
 * @token: Excutable Command
 * @value: Dirctory containing the command
 *
 * Return: the full path of null if failed
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}
/**
 * _getenv - Gets The Value Of the variable
 * @name: Environment Variable Name
 *
 * Return: The Value of the Environment Variable or NULL.
 */
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int a, e, b;

	nl = _strlen(name);
	for (a = 0 ; environ[a]; a++)
	{
		if (_strncmp(name, environ[a], nl) == 0)
		{
			vl = _strlen(environ[a]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			b = 0;
			for (e = nl + 1; environ[a][e]; e++, b++)
			{
				value[b] = environ[a][e];
			}
			value[b] = '\0';

			return (value);
		}
	}

	return (NULL);
}
