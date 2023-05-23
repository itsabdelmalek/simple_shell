#include "shell.h"

/**
 * _strcmp - Compares Two Strings
 * @s1:String 1
 * @s2:String 2
 *
 * Return: 0 if they're dentical Otherwise returns difference
 */
int _strcmp(char *s1, char *s2)
{
int cmp = 0, a, len1, len2;
len1 = _strlen(s1);
len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (a = 0; s1[a]; a++)
	{
		if (s1[a] != s2[a])
		{
			cmp = s1[a] - s2[a];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _isalpha - Checks if a character is alphabtic
 * @c: char to be checked
 *
 * Return: 1 on success 0 If failed
 */
int _isalpha(int c)
{
if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _itoa - Convert Integer To Char
 * @n: Int To be processed
 *
 * Return: Pointer to the char
 */
char *_itoa(unsigned int n)
{
	int len = 0, a = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[a] = (n % 10) + '0';
		n /= 10;
		a++;
	}
	s[a] = (n % 10) + '0';
	array_rev(s, len);
	s[a + 1] = '\0';
	return (s);
}
/**
 *  array_rev - Reverse an array
 * @arr:Array to be reversed
 * @len:Length Of the Array
 *
 * Return: Void
 */
void array_rev(char *arr, int len)
{
	int a;
	char tmp;

	for (a = 0; a < (len / 2); a++)
	{
		tmp = arr[a];
		arr[a] = arr[(len - 1) - a];
		arr[(len - 1) - a] = tmp;
	}
}
/**
 * intlen - Determines Length Of Integer
 * @num: integer to be processed
 *
 * Return: value of the lenght
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
