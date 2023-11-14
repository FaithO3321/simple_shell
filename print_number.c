#include "shell.h"
/**
 * print_digits - Function that prints digits from 0 to 9
 * Return: 0
*/
int print_digits(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		_putchar(i + '0');
	}
	_putchar('\n');

	return (0);
}
