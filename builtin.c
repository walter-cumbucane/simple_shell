#include "shell.h"

/**
 * isexit - checks whether the user prompted the exit command or not
 * @command: the line prompted by the user
 *
 * Return: 1 if the user prompted exit, 0 otherwise.
 */

int isexit(char *command)
{
	if (_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

/**
 * isenv - checks whether the user prompted the env command or not
 * @line: the line prompted by the user
 * @envin : environment variable
 *
 * Return: 1 if the user prompted env, 0 otherwise.
 */

int isenv(char **envin, char *line)
{
	char *line_copy;

	line_copy = malloc(_strlen(line) + 1);
	check_if_error(line_copy);
	_strcpy(line_copy, line);
	strtok(line_copy, " \n");
	if (_strcmp(line_copy, "env") == 0)
	{
		while (*envin != NULL)
		{
			write(1, *envin, _strlen(*envin));
			write(1, "\n", 1);
			envin++;
		}
		free(line_copy);
		free(line);
		return (1);
	}
	free(line_copy);
	return (0);
}

/**
 * check_exit - set the integer to 402
 * @args: command-line arguments to the executed binary
 * @line : line prompted by the user
 * @copy_line : a copy of the line prompted by the user
 * @err : exit controller
 * Return: nothing
 */

void check_exit(char **args, char *line, char *copy_line, int err)
{
	if (isexit(args[0]) == 1)
	{
		if (err == 0)
		{
			free_array(args, line, copy_line);
			exit(0);
		}
		else if (err == 2)
		{
			free_array(args, line, copy_line);
			exit(2);
		}
		else if (err == 127)
		{
			free_array(args, line, copy_line);
			exit(127);
		}
	}
}
