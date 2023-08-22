#include <string.h>
#include <stdio.h>

int main()
{
	char str[] = "Hello World!";
	const char s[2] = " ";
	char *token;

	printf("%s\n", str);

	token = strtok(str, s);

	while(token != NULL)
	{
		printf("%s\n", token);

		token = strtok(NULL, s);
	}
	return (0);
}
