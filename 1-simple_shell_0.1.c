#include "main.h"

/*reads user input*/
char *read_input(ssize_t input, char *lineptr);
/*prints prompt*/
void print_prompt(void);
/*tokenizes user input*/
char **tokenize_args(char *lineptr, char **args);

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
int i, status, process, interactive;
char *line_read = NULL, **env_var = environ, **args_tok, *lineptr, **args = NULL;
size_t n = 0;
ssize_t input;

for (i = 0; ; i++)
{
interactive = isatty(STDIN_FILENO);
if (interactive == 1)
print_prompt();

input = getline(&line_read, &n, stdin);

lineptr = read_input(input, line_read);

if (lineptr == NULL)
continue;

args_tok = tokenize_args(lineptr, args);

if (args == NULL)
continue;

process = fork();
if (process == 0)
{
if (execve(args_tok[0], args_tok, env_var) == -1)
{

perror("./hsh ");

if (interactive == 0)
{
perror("./hsh ");
exit(EXIT_FAILURE);
}
}
}

else if (process > 0)
{
waitpid(process, &status, 0);
free(line_read);
for (i = 0; args_tok[i] != NULL; i++)
free(args_tok[i]);
}

else
{
perror("fork failed...");
exit(EXIT_FAILURE);
}

}
free(args);
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
 *@input: number of lines read by getline
 *@lineptr: string containing user input
 *Return: line read
 */

char *read_input(ssize_t input, char *lineptr)
{
size_t i = 0;

if (input == -1)
{
_putchar('\n');
exit(EXIT_SUCCESS);
}

if (lineptr[i] == '\n' || lineptr[i] == 32)
return (NULL);

if (lineptr[input - 1] == '\n')
lineptr[input - 1] = '\0';

return (lineptr);
}

/**
 *tokenize_args- tokenizes the arguments
 *@lineptr: line read from stdin
 *Return: pointer to pointer of tokenized string
 */
char **tokenize_args(char *lineptr, char **args)
{
char *tokens;
int j = 0, k = 0;
size_t i;
if (lineptr == NULL)
return (NULL);

while (lineptr[i] != '\0')
i++;

i += 1;

/*tokenize arguments*/
tokens = strtok(lineptr, "");
while (tokens != NULL)
{
while (tokens[k] != '\0')
k++;

args[j] = malloc(sizeof(char) * k);
if (args[j] == NULL)
return (NULL);

for (i = 0; tokens[i] != '\0'; i++)
args[j][i] = tokens[i];

tokens = strtok(NULL, "");
j++;
}
args[j] = NULL;

return (args);
}

