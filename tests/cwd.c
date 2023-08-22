#include <stdio.h>
#include <unistd.h>

int main()
{
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("Error:");
	}
	else
	{
		printf("%s\n", cwd);
	}
	return (0);
}
