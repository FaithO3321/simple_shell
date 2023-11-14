#include "shell.h"
/**
 * global_environ_cmd - Function to check for global environment commands
 * @env_cmd: input variables for the shell environment
 * Return: variable content
*/
char *global_environ_cmd(char *env_cmd)
{
	int i = 0;
	const char s[] = "=";
	char *env_opt, *cop_env;
	char *cop_env_opt;

	if (env_cmd != NULL)
	{
		if (environ == NULL)
			return (NULL);
		cop_env = string_dup(environ[i]);

		while (cop_env != NULL)
		{
			env_opt = strtok(cop_env, s);
			if (custom_string_compare(env_opt, env_cmd) == 0)
			{
				env_opt = strtok(NULL, s);
				cop_env_opt = string_dup(env_opt);
				free(cop_env);
				return (cop_env_opt);
			}
			i++;
			free(cop_env);
			cop_env = string_dup(environ[i]);
		}
	}
	return (NULL);
}
