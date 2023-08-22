#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - super simple shell, taking commands and only exits on EOF or Ctrl-D
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 *
 * Return: Always zero on success, else exits on execution errro
 */
int main(int ac, char **av, char **env)
{
	char *line, *args[2];
	size_t len = 0;
	int exec, status;
	pid_t pid;

	while (1) /* looping the prompt */
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}
		if (getline(&line, &len, stdin) == -1)
		{
			exit(98);
		}
		strtok(line, "\n");

		args[0] = line;
		args[1] = NULL;

		pid = fork();
		if (pid == 0)
		{
			exec = execve(args[0], args, env); /* calling for execution of command/s */
			if (exec == -1)
			{
				printf("./shell: No such file or directory\n");
				exit(98);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("Error:");
		}
	}
	free(line);
	return (0);
}
