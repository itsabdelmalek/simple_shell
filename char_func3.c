#include "shell.h"
/**
 * _strcpy - Copies from Source To Destination
 * @dest: Destination
 * @src: Source
 *
 * Return: value
 */
char *_strcpy(char *dest, char *src)
{
int a;

a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
dest[a] = '\0';
return (dest);
}
/**
 * _strcat - Concates Two Strings
 * @dest: 1st string to concates
 * @src: 2nd String to concates
 *
 * Return: value of the string
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - Locates Char in string
 * @s: String Search In
 * @c: Char To Search For
 *
 * Return: Pointer To the char
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}
/**
 * _strncmp - Compares Characters Of Two Strings.
 * @s1: 1st String
 * @s2: 2st String.
 * @n: number Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match, 0 If they do
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	if (s1 == NULL)
		return (-1);
	for (a = 0; a < n && s2[a]; a++)
	{
		if (s1[a] != s2[a])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - Duplicates A String
 * @str: String to be duplicated
 *
 * Return: value of dublicated String or 0 if Failed
 */
char *_strdup(char *str)
{
	size_t len, a;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (a = 0; a <= len; a++)
	{
		str2[a] = str[a];
	}

	return (str2);
}
