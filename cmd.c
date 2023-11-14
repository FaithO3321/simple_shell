#include "shell.h"
/**
 * add_command - Concatenates a command to a directory path
 * @directory_path: path for directories
 * @command: command type passed
 *
 * Description:
 * this function conactenates a command to a directory path as
 * parameters and creates a new dynamically allocated string
 *
 * Return: path of command
 */
char *add_command(char *directory_path, char *command)
{
	int a;
	int b = 0;
	int array1, array2;
	char *path_for_command = NULL;

	if (directory_path == NULL || command == NULL)

		return (NULL);
	array1 = custom_length(directory_path);
	array2 = custom_length(command);
	path_for_command = malloc(array1 + array2 + 2);

	if (path_for_command == NULL)
		return (NULL);
	for (a = 0; directory_path[a] != '\0'; a++)
	{
		path_for_command[a] = directory_path[a];
	}
	if (directory_path[a - 1] != '/')
	{
		path_for_command[a] = '/';
		a++;
	}
	while (command[b] != '\0')
	{
		path_for_command[a + b] = command[b];
		b++;
	}
	path_for_command[a + b] = '\0';
	return (path_for_command);
}

/**
 * custom_length - length of the string
 * @array: string in the length
 * Return: print all the string
 */
int custom_length(const char *array)
{
	int size = 0;

	if (array == NULL)
	{
		return (0);
	}
	while (array[size] != '\0')
	{
		size++;
	}
	return (size);
}

