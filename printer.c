#include "shell.h"

/**
 * print_number - Print Unsigned Integer
 * @n: Unisigned Integer to be printed
 *
 * Return: Void
 */
void print_number(unsigned int n)

{
	unsigned int a = n;

	if ((a / 10) > 0)
		print_number(a / 10);

	_putchar(a % 10 + '0');
}
/**
 * print_num_in - Prints Number usig Putchar
 * @n: Integer to be printed
 *
 * Return: void
 */
void print_num_in(int n)
{
	unsigned int a = n;

	if (n < 0)
	{
		_putchar('-');
		a = -a;
	}
	if ((a / 10) > 0)
		print_number(a / 10);

	_putchar(a % 10 + '0');
}
