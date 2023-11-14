#include "shell.h"
/**
 * _putchar - Writes a given character to stdout
 * @a: the character to be displayed on stdout
 * Return: 0 on success, -1 on error
*/
int _putchar(char a)
{
	return (write(1, &a, 1));
}
