#ifndef SHELL_H
#define SHELL_H

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int count_tokens(char *line_copy);
void free_this(char **args, char *line_copy);
void tokenization(char **args, char *line);


#endif
