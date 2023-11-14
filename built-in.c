#include "shell.h"
/**
 * confirm_built_in_cmd  - Confirms for presence of built-in commands
 * @confirm: checks the for built-in commands
 * @args: number of arguments passed
 * Return: 0 Success, -1 no built-in command found
 */
int confirm_built_in_cmd(char **args, int confirm)
{
	char *parameters[2] = {
		"exit",
		"env"
	};
	int number = 0;

	while (number < 2)
	{
		if (custom_string_compare(args[0], parameters[number]) == 0)
			break;
		number++;
	}
	if (number == 2)
	{
		return (-1);
	}
	if (custom_string_compare(parameters[number], "exit") == 0)
	{
		free(args[0]);
		exit(confirm);
	}
	if (custom_string_compare(parameters[number], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		write(1, environ, 1000);
	}
	return (0);
}
