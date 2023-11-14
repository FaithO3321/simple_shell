#include "shell.h"
/**
 * check_process - Function to check a running process
 * @pr_name: name of the process
 * Return: 0 for running process, -1 for a process not running
*/
int check_process(char *pr_name)
{
	FILE *fp;

	fp = fopen(pr_name, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	fclose(fp);
	return (0);
}

/**
 * parse_input - Function to parse input string to array of commands
 * @input: string to parse
 * @parsed: array of parsed commands
 * Return: number of parsed commands
*/
int parse_input(char *input, char **parsed)
{
	int index = 0;
	char *token;

	token = strtok(input, " \n\t\r");

	while (token != NULL)
	{
		parsed[index] = token;
		index++;
		token = strtok(NULL, " \n\t\r");
	}
	parsed[index] = NULL;
	return (index);
}

/**
 * free_array - Funtion to free memory for array
 * @array: the array to be freed
 * @size: number of array elements
*/
void free_array(char **array, int size)
{
	int x;

	for (x = 0; x < size; x++)
	{
		free(array[x]);
	}
}
