#include "shell.h"
/**
 * main - Entry point for custom shell
 * Return: 0 sucess
 */
int main(void)
{
	size_t buff_size = 0;
	ssize_t read_inp = 0;
	char *use_input = NULL, *args[20];
	int add = 1, stat = 0, check = 0, exit = 0;
	int built_in = 0;

	output_prompt("$ ", 2);
	read_inp = getline(&use_input, &buff_size, stdin);
	while (read_inp != -1)
	{
		if (*use_input != '\n')
		{
			parse_input(use_input, args);
			if (args[0] != NULL)
			{
				check = check_process(args[0]);
				if (check != 0)
				{
					stat = locate_executable(args);
					if (stat == 0)
						check = execute_process(args), free(use_input), free(*args);
					else
					built_in = confirm_built_in_cmd(args, exit);
					if (built_in != 0)
						exit = error_output(args, add), free(use_input);
				}
				else
					exit = execute_process(args), free(use_input);
			}
			else
				free(use_input);
		}
		else if (*use_input == '\n')
			free(use_input);
		use_input = NULL, add++;
		output_prompt("$ ", 2), read_inp = getline(&use_input, &buff_size, stdin);
	}
	release_last_memory(use_input);
	return (exit);
}
