#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/**###### environ ######*/

extern char **environ;

/**###### string functions ######*/

char *_strtokn(char *str, const char *tok);
unsigned int checks_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/**###### memory handeling ####*/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/**###### inputs and prompt ######*/

void prompt(void);
void signal_to_handel(int sign);
char *_getline(void);

/** #### builtin functions #####*/

void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int r);
int dis_envr(char **cmd, int r);
int change_dir(char **cmd, int r);
int print_echo(char **cmd);
int disp_help(char **cmd, int r);
int echo_bultn(char **cmd, int r);
void exit_bultn(char **cmd, char *input, char **argv, int c);

/** #### printer and errors ####*/

void print_number(unsigned int n);
void print_num_in(int n);
void print_error(char *line, int c, char **argv);
void _prnterror(char **argv, int c, char **cmd);

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 *
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int r);
} bul_t;

/** ###### parsser and extractor commands ###*/

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int r);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void handle_file(char *line, int counter, FILE *fd, char **argv);
void exit_bult_for_file(char **cmd, char *line, FILE *fd);

#endif

