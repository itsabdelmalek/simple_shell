#include "shell.h"

/**
 * exit_bultn - Exit Statue
 * @cmd: Parsed Command
 * @input: Input by user
 * @argv: name of Program
 * @c: Count
 *
 * Return: void
 */
void  exit_bultn(char **cmd, char *input, char **argv, int c)
{
	int statue, a = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][a])
	{
		if (_isalpha(cmd[1][a++]) != 0)
		{
			_prnterror(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}
/**
 * change_dir - Change Directory
 * @cmd: Parsed Command
 * @r: Statue Last Command Excuted
 * Return: 0 on Succes 1 if Failed
 */
int change_dir(char **cmd, __attribute__((unused))int r)
{
	int val = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		val = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		val = chdir(getenv("OLDPWD"));
	}
	else
		val = chdir(cmd[1]);

	if (val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (val != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * dis_envr - Display variable envr
 * @cmd: Command parsed
 * @r: Statue of Last command
 * Return: Always 0 (success)
 */
int dis_envr(__attribute__((unused)) char **cmd, __attribute__((unused)) int r)
{
size_t a;
	int len;

	for (a = 0; environ[a] != NULL; a++)
	{
		len = _strlen(environ[a]);
		write(1, environ[a], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * disp_help - Displays Help
 * @cmd: command parsed
 * @r: Statue Of Last Command
 * Return: 0 on Succes -1 if Failed
 */
int disp_help(char **cmd, __attribute__((unused))int r)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_bultn - Excute Echo
 * @st: Statue Of Last Command
 * @cmd: Parsed Command
 *
 * Return: Always 0
 */
int echo_bultn(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_num_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1)
}
