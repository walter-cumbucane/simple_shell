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
 * free_array - set the integer to 402
 * @args: command-line arguments to the executed binary
 * @line : line prompted by the user
 * @line_copy : copy of the line prompted by the user
 * Return: nothing
 */

void free_array(char **args, char *line, char *line_copy)
{
	int i;

	if (args == NULL)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	free(line);
	free(line_copy);
}



/**
 *_strcmp -checks for a lowercase character
 *@s1: letter being tested
 *@s2 : letter being tested
 * Return: Always 0
 */

int _strcmp(char *s1, char *s2)
{
	int dif;
	int i;

	i = 0;
	while (7 > 5)
	{
		if (*(s1 + i) == 0 || *(s2 + i) == 0)
		{
			dif = *(s1 + i) -  *(s2 + i);
			break;
		}
		else
		{
			dif = *(s1 + i) - *(s2 + i);
			if (dif != 0)
			{
				break;
			}
			i++;
		}

	}
	return (dif);
}

