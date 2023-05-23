#include "shell.h"

/**
 * checks_delim - Checks If a character matches any other.
 * @c: Character To Check
 * @str: String To Check
 *
 * Return: 1 on Succes, 0 if Failed
 */
unsigned int checks_delim(char c, const char *str)
{
	unsigned int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (c == str[a])
			return (1);
	}
	return (0);
}

/**
 * _strtokn - Token to the String
 * @str: String
 * @delm: Delimiter
 *
 * Return: Pointer to the Token Or 0 if failed
 */
char *_strtokn(char *str, const char *delm)
{
	static char *stc;
	static char *stn;
	unsigned int a;

	if (str != NULL)
		stn = str;
	stc = stn;
	if (stc == NULL)
		return (NULL);
	for (a = 0; stc[a] != '\0'; a++)
	{
		if (checks_delim(stc[a], delm) == 0)
			break;
	}
	if (stn[a] == '\0' || stn[a] == '#')
	{
		stn = NULL;
		return (NULL);
	}
	stc = stn + a;
	stn = stc;

	for (a = 0; stn[a] != '\0'; a++)
	{
		if (checks_delim(stn[a], delm) == 1)
			break;
	}
	if (stn[a] == '\0')
		stn = NULL;
	else
	{
		stn[a] = '\0';
		stn = stn + a + 1;
		if (*stn == '\0')
			stn = NULL;
	}
	return (stc);
}
