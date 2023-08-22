#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	extern char **environ; 
	char *buffer;
	size_t len = 10;
	int status;
	pid_t child_pid;
	int waitt;
	char *command;

	printf("$");
	buffer = malloc(sizeof(char) * 10);
	status = getline(&buffer, &len, stdin);
	if (status == -1)
		exit(98);

	command = strtok(buffer, "\n");
	char *argv[] = {command, NULL};
	child_pid = fork();
	if (child_pid == -1)
	{
		write(2, "Error child", 11);
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			write(2, "Error exec", 10);
			return (1);
		}
	}
	else
	{
		wait(&waitt);
	}
	return (0);
}
