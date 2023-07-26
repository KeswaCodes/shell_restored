#include "main.h"

/**
 *handle_path- handles the command line with arguments
 *@lineptr: command line string
 *Return: pointer to path matching input
 */

char *handle_path(char *lineptr)
{

char *path, *tokens, *path_token;
char *command = lineptr;
int i = 0, m;

path = _getenv("PATH");
if (path == NULL)
return (NULL);

tokens = strtok(path, ":");
while (tokens != NULL)
{
for (i = 0; tokens[i] != '\0'; i++)
;

path_token = malloc(sizeof(char) * (i + 2));
if (path_token == NULL)
return (NULL);
for (i = 0; tokens[i] != '\0'; i++)
path_token[i] = tokens[i];

path_token[i] = '/';
i++;
for (m = 0; command[m] != ' ' && command[m] != '\0'; m++)
path_token[i + m] = command[m];

path_token[i + m] = '\0';
if (access(path_token, X_OK) == 0)
return (path_token);

tokens = strtok(NULL, ":");
}


return (path_token);
}
/**
 *execve_path- executes the function if path matches
 *@path: string of path
 *@lineptr: command along with options, if available
 *Return: -1 always, to keep shell running
 */

int execve_path(char *path, char *lineptr)
{

char *args, **arg_token, **env_var = environ;
int i = 0, pid, status, j;

pid = fork();

if (pid == 0)
{
args = strtok(lineptr, " ");
while (args != NULL)
{
for (j = 0; args[j] != '\0'; j++)
;

arg_token = malloc(sizeof(char *) * j);
for (i = 0; args[i] != '\0'; i++)
{
arg_token[i] = args;
}
args = strtok(NULL, " ");
}

arg_token[i] = NULL;
execve(path, arg_token, env_var);
return (-1);
}
else if (pid > 0)
{
wait(&status);
return (-1);
}

else
return (-1);

return (-1);
}
