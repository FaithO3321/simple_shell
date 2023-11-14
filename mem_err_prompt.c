#include "shell.h"

void print_alphabets(int add);

/**
 * release_last_memory -  Function to free memory of last program
 * @input_cmd: input applied to the program
*/
void release_last_memory(char *input_cmd)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(input_cmd);
	}
	if (!isatty(STDIN_FILENO))
		free(input_cmd);
}

/**
 * error_output - Function to show encountered errors
 * @c: arguments passed
 * @add: number of executions
 * Return: errors encountered
*/
int error_output(char **c, int add)
{
	char *not_interactive = "./hsh";
	char *interactive = "hsh";

	if (isatty(STDIN_FILENO))
	{
		write(2, interactive, 3);
	}
	else
	{
		write(2, not_interactive, 5);
	}
	write(2, ": ", 2);
	print_alphabets(add);
	write(2, ": ", 2);
	write(2, c[0], custom_length(c[0]));
	write(2, ": not found\n", 12);
	return (127);
}

/**
 * output_prompt -  Function to display prompt
 * @str: pointer to the string to be printed
 * @length: string size
 * Return: 0 success
*/
int output_prompt(const char *str, unsigned int length)
{
	int i;

	if (isatty(STDIN_FILENO))
	{
		i = write(1, str, length);
			if (i == -1)
			{
				return (-1);
			}
	}
	return (0);
}
