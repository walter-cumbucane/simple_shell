#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 64

/**
 * parse_line - splits the input line into arguments
 * @line: the input line
 * @args: the array of arguments
 *
 *This function takes an input line and splits it into arguments using strtok.
 *The arguments are stored in the args array.
 */
void parse_line(char *line, char **args)
{
	int i = 0;
	strtok(line, "\n");
	args[i] = strtok(line, " ");
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
}

/**
 * execute_command - executes a command
 * @args: the array of arguments
 * @env: the environment variable
 *
 *This function takes an array of arguments and an environment variable
 * It checks if the first argument is a path to an executable file or if it is
 * in the PATH environment variable and executes it using execve.
 */
void execute_command(char **args, char **env)
{
	int exec;

	if ((args[0][0] == '.' && args[0][1] == '/') || (args[0][0] == '/'))
	{
		exec = execve(args[0], args, env);
		if (exec == -1)
		{
			write(1, "./shell: No such file or directory\n", 35);
			exit(98);
		}
	}
	else
	{
		char *path = getenv("PATH");
		char *path_copy = strdup(path);
		char *token;
		char buffer[1024];

		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			strcpy(buffer, token);
			strcat(buffer, "/");
			strcat(buffer, args[0]);
			if (access(buffer, F_OK) == 0)
			{
				exec = execve(buffer, args, env);
				if (exec == -1)
				{
					write(1, "./shell: No such file or directory\n", 35);
					exit(98);
				}
			}
			token = strtok(NULL, ":");
		}
		free(path_copy);
		write(1, "./shell: No such file or directory\n", 35);
		exit(98);
	}
}

/**
 * check_command - checks if a command exists
 * @args: the array of arguments
 * @env: the environment variable
 *
 * This funciton takes an array of arguments and an environment variable.
 * It checks if the command specified in args[0] exists in the PATH environment
 * variable or is a path to an executable file.
 *
 * Return: 1 If the command exists.
 * Otherwise, it returns 0.
 */
int check_command(char **args, char **env)
{
	char *path;
	char *path_copy;
	char *token;
	char buffer[1024];
	(void)env;

	path = getenv("PATH");
	path_copy = strdup(path);

	if (access(args[0], F_OK) == 0)
		return (1);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		strcpy(buffer, token);
		strcat(buffer, "/");
		strcat(buffer, args[0]);
		if (access(buffer, F_OK) == 0)
		{
			free(path_copy);
			return (1);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}

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
	char *line;
	char *args[MAX_ARGS];
	size_t len = 0;
	int status;
	pid_t pid;
	(void)av;
	(void)ac;

	while (1) /* looping the prompt */
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		if (getline(&line, &len, stdin) == -1)
			exit(98);
		parse_line(line, args);

		if (!check_command(args, env))
		{
			write(1, "./shell: No such file or directory\n", 35);
		}

		pid = fork();
		if (pid == 0)
		{
			execute_command(args, env);
			execve(args[0], args, env); /* calling for execution of command/s */
		}
		else if (pid > 0)
			wait(&status);
		else
			perror("Error:");
	}
	free(line);
	return (0);
}
