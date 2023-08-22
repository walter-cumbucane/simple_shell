#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t child_pid;
	int i;
	int status;
	char *line[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(line[0], line, NULL) == -1)
			{
				perror("Error:");
			}
			exit(0);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
