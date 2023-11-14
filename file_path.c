#include "shell.h"
/**
 * locate_executable - Function to find executable path
 * @args: array of comands and arguments
 * Return: 0 success, -1 on failure
*/
int locate_executable(char **args)
{
	char *path, *directory, *command;

	path = getenv("PATH");
	if (!path)
		return (-1);

	path = strdup(path);
	directory = strtok(path, ":");

	while (directory)
	{
		command = malloc(strlen(directory) + strlen(args[0]) + 2);
		strcpy(command, directory);
		strcat(command, "/");
		strcat(command, args[0]);

		if (access(command, X_OK) == 0)
		{
			args[0] = command;
			return (0);
		}

		directory = strtok(NULL, ":");
		free(command);
	}

	free(path);
	return (-1);
}
