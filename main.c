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
	char *line, *line_copy, **args;
	int result, child_status;
	size_t len = 20;
	pid_t pid;

	(void)ac, (void)av;
	while (1) /* looping the prompt */
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		line = NULL;
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(0);
		}
		if (check_if_is_empty(line) == 1)
			continue;
		if (isenv(env, line) == 1)
			continue;
		line_copy = malloc(_strlen(line) + 1);
		check_if_error(line_copy);
		_strcpy(line_copy, line);
		result = count_tokens(line_copy, line);
		if (result == -1)
			continue;
		args = malloc(sizeof(char *) * result);
		check_if_error_array(args);
		tokenization(args, line);
		handle_exit(args, line, line_copy);
		pid = fork();
		child_status = execute_command(pid, env, args);
		free_array(args, line, line_copy);
		if (!isatty(0))
			exit(child_status);
	}
	return (child_status);
}
