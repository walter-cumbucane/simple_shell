#include <stdio.h>
#include <stdlib.h>

/**
 * main - test user input from command line
 * @ac: number of command-line arguments passed to program
 * @av: array of pointers to null-terminated string
 *
 * Return: Always zero on success
 */
int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        printf("%s", line);
        printf("$ ");
    }
    free(line);
    exit(EXIT_SUCCESS);
}
