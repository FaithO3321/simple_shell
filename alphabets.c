#include "shell.h"
/**
 * print_alphabets - Function to print alphabets
 * @add: 0 for uppercas, 1 fr lowercase
*/
void print_alphabets(int add)
{
	char c;

	char begin = (add == 0) ? 'A' : 'a';
	char stop = (add == 0) ? 'Z' : 'z';

	for (c = begin; c <= stop; c++)
	{
		printf("%c", c);
	}
	printf("\n");
}
