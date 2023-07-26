#include "main.h"
/* function tokenizes arguments */
char **tokenize_args(char *lineptr);

/* function prints a prompt*/
void print_prompt(void);

/*function reads input*/
char *read_input(void);

/**
 *main- simple shell by zinksw@gmail.com
 *@argc: argument count
 *@argv: array of arguments
 *Return: 1 - success, -1 failure
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
int i, status, process, interactive;
char *lineptr = NULL, **env_var = environ, **args;

for (i = 0; ; i++)
{
interactive = isatty(STDIN_FILENO);
if (interactive == 1)
print_prompt();

lineptr = read_input();

if (lineptr == NULL)
continue;

args = tokenize_args(lineptr);
if (args == NULL)
continue;

process = fork();
if (process == 0)
{
execve(args[0], args, env_var);
if (interactive == 0)
perror("./hsh");
free(args);
exit(EXIT_FAILURE);
}

else if (process > 0)
wait(&status);

else
return (-1);
}
free(lineptr);
return (0);
}
/**
 *print_prompt- prints a prompt "$ "
 *Return: void
 */
void print_prompt(void)
{
char *data = "$ ";

write(1, data, 3);
}
/**
 *read_input- reads input from stdin
 *Return: line read
 */
char *read_input(void)
{
char *lineptr = NULL;
size_t n = 0, i = 0;
ssize_t input;
int m;

input = getline(&lineptr, &n, stdin);

if (input == -1)
{
_putchar('\n');
exit(EXIT_SUCCESS);
}

if (lineptr[i] == '\n' || lineptr[i] == 32)
return (NULL);

if (lineptr != NULL)
{
if (lineptr[input - 1] == '\n')
lineptr[input - 1] = '\0';
}

for (i = 0; lineptr[i] != '\0'; i++)
{
if (lineptr[i] == 'e' && lineptr[i + 1] == 'n' && lineptr[i + 2] == 'v')
print_env();
}

for (m = 0; m < 4; m++)
{
if (lineptr[m] != "exit"[m])
break;
}
if (m == 4)
exit(EXIT_SUCCESS);

return (lineptr);
}

/**
 *tokenize_args- tokenizes the arguments
 *@lineptr: line read from stdin
 *Return: pointer to pointer of tokenized string
 */
char **tokenize_args(char *lineptr)
{
char **args, *tokens;
int j = 0, i = 0;

if (lineptr == NULL)
return (NULL);

while (lineptr[i] != '\0')
i++;

i += 1;

/*malloc the space for the arguments*/
args = malloc(sizeof(char *) * i);
if (args == NULL)
return (NULL);

/*tokenize arguments*/
tokens = strtok(lineptr, " ");
while (tokens != NULL)
{
args[j] = tokens;
tokens = strtok(NULL, " ");
j++;
}
args[j] = NULL;

return (args);
}
