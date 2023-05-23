#include "shell.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: Parsed Command
 * @r: statue of last Excute
 * Return: 0 on Succes -1 if Fail
 */

int handle_builtin(char **cmd, int r)
{
	 bul_t bul[] = {
		{"cd", change_dir},
		{"env", dis_envr},
		{"help", disp_help},
		{"echo", echo_bultn},
		{NULL, NULL}
	};
	int a = 0;

	while ((bul + a)->command)
	{
		if (_strcmp(cmd[0], (bul + a)->command) == 0)
		{
			return ((bul + a)->fun(cmd, r));
		}
		a++;
	}
	return (-1);
}
/**
 * check_cmd - Excutes Simple Shell Command
 *
 * @cmd: Parsed Command
 * @input: User Input
 * @c: Shell Excution Time
 * @argv: Program
 * Return: 1 on success, 0 if excuted -1 if wrong
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handle
 * @sign: Captured Signal
 *
 * Return: Void
 */
void signal_to_handel(int sign)
{
	if (sign == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
