#include "shell.h"
#include "shell"
/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv: Argument Value
 *
 * Return: Exit Value
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, str = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bultn(cmd, input, argv, counter);
		}
		else if (check_builtin(cmd) == 0)
		{
			str = handle_builtin(cmd, str);
			free_all(cmd, input);
			continue;
		}
		else
		{
			str = check_cmd(cmd, input, counter, argv);

		}
		free_all(cmd, input);
	}
	return (statue);
}
/**
 * check_builtin - check builtin
 * @cmd: command to check
 *
 * Return: 0 on Succes -1 if Failed
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int a = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + a)->command)
	{
		if (_strcmp(cmd[0], (fun + a)->command) == 0)
			return (0);
		a++;
	}
	return (-1);
}
/**
 * creat_env - Creat Array of Variables
 * @env: Array of Enviroment Variable
 *
 * Return: Void
 */
void creat_env(char **env)
{
	int a;

	for (a = 0; environ[a]; a++)
		env[a] = _strdup(environ[a]);
	env[a] = NULL;
}
