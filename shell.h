#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int count_tokens(char *line_copy, char *line);
void free_this(char **args, char *line_copy);
void tokenization(char **args, char *line);
int _strcmp(char *s1, char *s2);
int isexit(char *line);
int isenv(char **envin, char *line);
int execute_command(pid_t pid, char **envin, char **args, int err);
int check_if_is_empty(char *line);
void free_array(char **args, char *line, char *line_copy);
void check_if_error(char *s);
void check_if_error_array(char **s);
void check_exit(char *line, int err);
int check_command(char **args, char *line, char *line_copy, char **av);

#endif
