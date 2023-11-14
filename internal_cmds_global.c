#include "shell.h"
/**
 * check_builtin_cmd - Function to check for commands in global paths
 * @str_loc: location of where string to be added with the command
 * @built_cmd: internal commands
 * Return: result of adding strings and commands
 */
char *check_builtin_cmd(char *str_loc, char *built_cmd)
{
	char *cmd_loc = NULL;
	int x, y = 0;
	int a1, a2;

	if (str_loc == NULL || built_cmd == NULL)
		return (NULL);
	a1 = string_length(str_loc);
	a2 = string_length(built_cmd);
	cmd_loc = malloc(a1 + a2 + 2);
	if (cmd_loc == NULL)
		return (NULL);
	for (x = 0; str_loc[x] != '\0'; x++)
	{
		cmd_loc[x] = str_loc[x];
	}
	if (str_loc[x - 1] != '/')
	{
		cmd_loc[x] = '/';
		x++;
	}
	while (built_cmd[y] != '\0')
	{
		cmd_loc[x + y] = built_cmd[y];
		y++;
	}
	cmd_loc[x + y] = '\0';
	return (cmd_loc);
}
