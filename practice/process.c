#include "main.h"
/**
 *process- handles the processes in the terminal
 *Return: void
 */

void process(char **lineptr, char **env)
{
pid_t pid;
int status;
  
pid = fork();
if (pid == 0)
execve(lineptr, );
else if (pid > 0)
wait(&status);
else
exit(EXIT_FAILURE);

}
