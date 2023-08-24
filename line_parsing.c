#include "shell.h"

/**
 * count_tokens - counts the number of tokens of the read line
 * @line_copy: a copy of the line read from the input
 * @line : the line prompted by the user
 * Return: the number of tokens of the read string
 */


int count_tokens(char *line_copy, char *line)
{
	int count = 0;
	char *token = NULL;

	token = strtok(line_copy, " \n");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \n");
	}
	if (count == 0)
	{
		free(line_copy);
		free(line);
		return (-1);
	}
	free(token);
	return (count);
}

/**
 * tokenization - set the integer to 402
 * @args: a pointer the integer we want to set to 98
 * @line : the line read from input
 * Return: nothing
 */


void tokenization(char **args, char *line)
{
	int i;
	char *token = NULL;

	token = strtok(line, " \n");
	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc((sizeof(char) * _strlen(token)) + 1);
		check_if_error(args[i]);
		_strcpy(args[i], token);
		token = strtok(NULL, " \n");
	}
	free(token);
	args[i] = NULL;
}

/**
 * check_if_is_empty -whether the line prompted by the user is empty or not
 * @line: the line prompted by the user
 *
 * Return: 1 if it is empty or 0 if it isn't empty
 */

int check_if_is_empty(char *line)
{
	int i, len;
	char *line_copy;

	line_copy = malloc(_strlen(line) + 1);
	check_if_error(line_copy);
	_strcpy(line_copy, line);
	strtok(line_copy, "\n");
	len = _strlen(line_copy);
	i = 0;
	while (i < len)
	{
		if (*(line + i) != ' ')
		{
			free(line_copy);
			return (0);
		}
		i++;
	}
	free(line_copy);
	free(line);
	return (1);
}
