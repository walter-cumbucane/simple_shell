#include "shell.h"



/**
 * check_if_error - set the integer to 402
 * @s: a pointer the integer we want to set to 98
 *
 * Return: nothing
 */

void check_if_error(char *s)
{
	if (s == NULL)
	{
		write(2, "Out of memory", _strlen("Out of memory"));
		exit(1);
	}
}

/**
 * check_if_error_array - set the integer to 402
 * @s: a pointer the integer we want to set to 98
 *
 * Return: nothing
 */

void check_if_error_array(char **s)
{
	if (s == NULL)
	{
		write(2, "Out of memory", _strlen("Out of memory"));
		exit(1);
	}
}
