#include "shell.h"

/**
 * count_tokens - counts the number of tokens of the read line
 * @line_copy: a copy of the line read from the input
 *
 * Return: the number of tokens of the read string
 */


int count_tokens(char *line_copy)
{
	int count = 0;
	int i;
	char *token;

	token = strtok(line_copy, " \n");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \n");
	}
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
	char *token;

	token = strtok(line, " \n");
	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(args[i], token);
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
}
