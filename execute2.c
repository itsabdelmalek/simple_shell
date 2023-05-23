#include "shell.h"

/**
 * read_file - Reads Command From File
 * @filename: name of the file
 * @argv: Program Name
 *
 * Return: -1 if failed or 0 on success
 */
void read_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		handle_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * handle_file - treates the file
 * @line: gets Line From A File
 * @counter: Error of Counter
 * @fp: description of file
 * @argv: Program Name
 *
 * Return : void
 */
void handle_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int sts = 0;

	cmd = parse_cmd(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_bult_for_file(cmd, line, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			sts = handle_builtin(cmd, sts);
			free(cmd);
		}
		else
		{
			sts = check_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}
/**
 * exit_bult_for_file - Exit Shell Case for the file
 * @line: gets Line From A File
 * @cmd: Command parsed
 * @fd: File Descriptor
 *
 * Return : void no return
 */
void exit_bult_for_file(char **cmd, char *line, FILE *fd)
{
	int statue, a = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][a])
	{
		if (_isalpha(cmd[1][a++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);
}
