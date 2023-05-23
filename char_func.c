#include "shell.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to write
 *
 * Return: On success 1 and -1 if failed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: integer
 *
 * Return: value of the char
 */
char *_strncpy(char *dest, char *src, int n)
{
int a;
a = 0;
	while (a < n && *(src + a))
	{
	*(dest + a) = *(src + a);
	a++;
	}
	while (a < n)
	{
	*(dest + a) = '\0';
	a++;
	}
	return (dest);
}
/**
 * _strlen - gives lenght of string
 * @s: string to be processed
 *
 * Return: value of int to lenght of str
 */

int _strlen(char *s)
{
	int a;

		for (a = 0; s[a] != '\0'; a++)
		{
			continue;
		}
return (a);
}

/**
 * _atoi - convert to an int
 * @s: string to be processed
 *
 * Return: value of integer
 */
int _atoi(char *s)
{
int a, b, n, e;

	a = n = 0;
	e = 1;
	while ((s[a] < '0' || s[a] > '9') && (s[a] != '\0'))
	{
		if (s[a] == '-')
			e *= -1;
		a++;
	}
	b = a;
	while ((s[b] >= '0') && (s[b] <= '9'))
	{
		n = (n * 10) + e * ((s[b]) - '0');
		b++;
	}
	return (n);
}
/**
 * _puts - print a string
 * @str: string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		_putchar(str[a]);
	}
_putchar('\n');
return;
}
