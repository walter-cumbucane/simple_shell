#include "shell.h"


/**
 * execute_command - executes the prompted command
 * @pid : the process identifier
 * @envin : environment variable
 * @args : command-line arguments to the executed command
 *
 * Return: nothing
 */

void execute_command(pid_t pid, char **envin, char **args)
{
	int exec;
	int status = 0;

	if (pid == 0)
	{
		exec = execve(args[0], args, envin); /* calling for execution of command/s */
		if (exec == -1)
		{
			write(2, "./shell: No such file or directory\n", 35);
			exit(0);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		write(2, "Error:", 6);
	}
}
