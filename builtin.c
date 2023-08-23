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
 * @line_copy : a copy of the line prompted by the user
 * Return: nothing
 */

int check_exit(char **args, char *line, char *line_copy)
{
	unsigned int i = 0, max_len = 10;
	unsigned int number = 0, max = 1 << ((sizeof(int) * 8) - 1);

	if (args[1])
	{
		if (*(*(args + 1) + 0) == 45)
		{
			i++;
			max_len++;
		}
		else if (*(*(args + 1) + 0) == 43)
		{
			i++;
			max_len++;
		}
		while (*(*(args + 1) + i))
		{
			if (i <= max_len && args[1][i] >= 48 && args[1][i] <= 57)
				number = (number * 10) + (args[1][i] - 48);
			else
				return (2);
			i++;
		}
	}
	else
		return (1);
	if (number > max - 1)
		return (2);
	free_array(args, line, line_copy);
	exit(number);
}

/**
 * handle_exit - set the integer to 402
 * @args: command-line arguments to the executed binary
 * @line : line prompted by the user
 * @line_copy : a copy of the line prompted by the user
 * Return: nothing
 */

void handle_exit(char **args, char *line, char *line_copy)
{
	if (isexit(args[0]) == 1)
	{
		if (check_exit(args, line, line_copy) == 1)
		{
			free_array(args, line, line_copy);
			exit(0);
		}
		else
		{
			free_array(args, line, line_copy);
			exit(2);
		}
	}
}
