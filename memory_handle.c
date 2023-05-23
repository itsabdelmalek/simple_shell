#include "shell.h"

/**
 * *_realloc -  Reallocates A Memory Block
 * @ptr: Pointer
 * @old_size: Previous Size Of The Pointer
 * @new_size: New Size Of The Pointer
 *
 * Return: void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}
/**
 * free_all - Free Array
 * @cmd: Pointer to the array
 * @line: Char Pointer
 *
 * Return: Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - Copies from Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size of memory
 *
 *Return: Void
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		dest[a] = src[a];
	}
	return (dest);
}
/**
 * fill_an_array - Fill An Array
 * @a: Void Pointer
 * @el: Integer
 * @len: Length of integer
 *
 *Return: Void
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int e = 0;

	while (e < len)
	{
		*p = el;
		p++;
		e++;
	}
	return (a);
}
/**
 * _calloc -  Allocates Memory For An Array
 * @size: Size
 *
 * Return: Void
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int e;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (e = 0; e < size; e++)
	{
		a[e] = '\0';
	}
	return (a);
}
