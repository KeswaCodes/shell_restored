#include "main.h"
/**
 *get_user_input- gets user input from stdin
 *Return: 1 (success), -1 otherwise
 */

void get_user_input(char **lineptr)
{
ssize_t input;
size_t n = 0;

input = getline(lineptr, &n, stdin);


if (input == -1)
{
printf("\n");
free(*lineptr);
exit(EXIT_SUCCESS);
}

if ((*lineptr)[0] == '\n' || (*lineptr)[0] == ' ')
return;

if (*lineptr != NULL)
{
if ((*lineptr)[input - 1] == '\n')
(*lineptr)[input - 1] = '\0';
}

return;

}
