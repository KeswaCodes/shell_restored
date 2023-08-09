#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
char *_strcat(char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
void exit_function(void);
void get_user_input(char **lineptr);
void process(char **lineptr, char **env);
#endif
