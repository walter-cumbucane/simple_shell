#include "shell.h"

/**
 * _strlen - set the integer to 402
 * @s: a pointer the integer we want to set to 98
 *
 * Return: nothing
 */

int _strlen(char *s)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * _strcpy - set the integer to 402
 * @dest: a pointer the integer we want to set to 98
 * @src : source message
 * Return: nothing
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (7 > 5)
	{
		if (*(src + i) == 0)
		{
			*(dest + i) = 0;
			break;
		}
		else
		{
			*(dest + i) = *(src + i);
			i++;
		}
	}
	return (dest);
}

/**
 * free_this - set the integer to 402
 * @args: command-line arguments to the executed binary
 * @line_copy : a copy of the line read from the input data
 * Return: nothing
 */


void free_this(char **args, char *line_copy)
{
	free(args);
	free(line_copy);
}

