#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - super simple shell, taking commands and only exits on EOF or Ctrl-D
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 *
 * Return: Always zero on success, else exits on execution errro
*/

int main(void)
{
	extern char **environ;
	char *line, *line_copy, **args;
	int exec, status, result;
	size_t len = 0;
	pid_t pid;

	while (1) /* looping the prompt */
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		if (getline(&line, &len, stdin) == -1)
			exit(98);
		line_copy = malloc(sizeof(line));
		_strcpy(line_copy, line);
		result = count_tokens(line_copy);
		args = malloc(sizeof(char *) * result);
		tokenization(args, line);
		pid = fork();
		if (pid == 0)
		{
			exec = execve(args[0], args, environ); /* calling for execution of command/s */
			free_this(args, line_copy);
			if (exec == -1)
			{
				write(1, "./shell: No such file or directory\n", 35);
				exit(98);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
			free_this(args, line_copy);
		}
		else
		{
			free_this(args, line_copy);
			perror("Error:");
		}
	}
	free(line);
	return (0);
}
