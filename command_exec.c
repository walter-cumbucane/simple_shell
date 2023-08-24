#include "shell.h"


/**
 * execute_command - executes the prompted command
 * @pid : the process identifier
 * @envin : environment variable
 * @args : command-line arguments to the executed command
 * @err : error controller
 * Return: nothing
 */

int execute_command(pid_t pid, char **envin, char **args, int err)
{
	int exec, i;

	if (pid == 0)
	{
		exec = execve(args[0], args, envin); /* calling for execution of command/s */
		if (exec == -1)
		{
			for (i = 1; args[i]; i++)
			{
				write(2, args[0], _strlen(args[0]));
				write(2, ": cannot access '", _strlen(": cannot access '"));
				write(2, args[i], _strlen(args[i]));
				write(2, "': No such file or ", _strlen("': No such file or "));
				write(2, "directory\n", _strlen("directory\n"));
			}
			exit(2);
		}
	}
	else if (pid > 0)
	{
		wait(&err);
		if (WIFEXITED(err))
		{
			return (WEXITSTATUS(err));
		}
		return (0);
	}
	else
	{
		write(2, "Error:", 6);
		return (1);
	}
	return (1);
}

/**
 * check_command - set the integer to 402
 *
 * @args: command-line arguments to the executed binary
 * @line : line prompted by the user
 * @line_copy : copy of the line prompted by the user
 * @av : array that contains all command-line arguments
 *
 * Return: nothing
 */

int check_command(char **args, char *line, char *line_copy, char **av)
{
	int result;

	result = access(args[0], F_OK);
	if (result == 0)
		return (0);
	write(2, av[0], _strlen(av[0]));
	write(2, " :1: ", _strlen(" :1: "));
	write(2, args[0], _strlen(args[0]));
	write(2, " not found\n", _strlen(": not found\n"));
	free_array(args, line, line_copy);
	return (127);
}
