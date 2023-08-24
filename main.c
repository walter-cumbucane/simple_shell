#include "shell.h"

/**
 * main - super simple shell, taking commands and only exits on EOF or Ctrl-D
 * @ac : argument counter
 * @av : array of all arguments as strings
 * @env : environment variable
 *
 * Return: Always zero on success, else exits on execution errro
*/

int main(int ac, char **av, char **env)
{
	char *line, *line_copy = NULL, **args = NULL;
	int result, err = 0;
	size_t len = 20;
	pid_t pid;

	(void)ac;
	while (1) /* looping the prompt */
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		line = NULL;
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(err);
		}
		if (check_if_is_empty(line) == 1)
			continue;
		check_exit(line, err);
		if (isenv(env, line) == 1)
			continue;
		line_copy = malloc(_strlen(line) + 1);
		check_if_error(line_copy);
		_strcpy(line_copy, line);
		result = count_tokens(line_copy, line);
		if (result == -1)
			continue;
		args = malloc((sizeof(char *)) * (result + 1));
		check_if_error_array(args);
		tokenization(args, line);
		err = check_command(args, line, line_copy, av);
		if (err == 127)
			continue;
		pid = fork();
		err = execute_command(pid, env, args, err);
		free_array(args, line, line_copy);
	}
	return (err);
}
