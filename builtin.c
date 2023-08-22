#include "shell.h"

/**
 * isexit - checks whether the user prompted the exit command or not
 * @line: the line prompted by the user
 *
 * Return: 1 if the user prompted exit, 0 otherwise.
 */

int isexit(char *line)
{
	char *line_copy;

	line_copy = malloc(_strlen(line) + 1);
	_strcpy(line_copy, line);
	strtok(line_copy, " \n");
	if (_strcmp(line_copy, "exit") == 0)
	{
		free(line_copy);
		free(line);
		return (1);
	}
	free(line_copy);
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
