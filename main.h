
#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

extern char **environ;
int print_env(void);
int _putchar(char c);
char *_getenv(const char *name);
void print_prompt(void);
char *handle_path(char *lineptr);
char *read_input(ssize_t input, char *lineptr);
char **tokenize_args(char *lineptr, char **args);
#endif
