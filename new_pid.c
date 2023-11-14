#include "shell.h"
/**
 * execute_process - Function to launch new pid
 * @arr: string of arguments
 * Return: 0 on success, exit status
 */
int execute_process(char **arr)
{
	int i = 0, j = 0;
	pid_t launched_pid = 0;

	launched_pid = fork();
	if (launched_pid == -1)
		output_prompt("failed\n", 7);
	else if (launched_pid == 0)
	{
		j = execve(arr[0], arr, environ);
		if (j == -1)
		{
			j = 126;
			perror("hsh");
			exit(j);
		}
		exit(0);
	}
	else
		wait(&i);
	j = WEXITSTATUS(i);
	return (j);
}
