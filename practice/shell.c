#include "main.h"
/**
 *main- main execution point
 *Return: 1 (success), -1 otherwise
 */

int main(void)
{
  pid_t pid;
  int status, i;
  ssize_t input;
  char *lineptr = NULL;
  size_t n = 0;

  for (i = 0; ; i++)
	{

	  if (isatty(STDIN_FILENO) == 1)
	  printf("$ ");

	  pid = fork();
	  if (pid > 0)
	    {
	      waitpid(pid, &status, 0);
	  break;
	    }
	  else if (pid == 0)
	    {
	   input = getline(&lineptr, &n, stdin);
	   if (input == -1)
	     {
	      free(lineptr);
	      printf("\n");
	   exit(EXIT_SUCCESS);
	     }

	   else if (input == 1)
	     continue;
	   else
	     printf("%s\n", lineptr);
	   
	    }
	  

	}
    
  free(lineptr);
  return (0);
}
