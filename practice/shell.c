#include "main.h"
/**
 *main- main execution point
 *Return: 1 (success), -1 otherwise
 */

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char **env)
{
char *lineptr = NULL;
int i = 0;  
  
while(1)
{
if (isatty(STDIN_FILENO) == 1)
printf(":)# ");

get_user_input(&lineptr);
if (*lineptr == '\n')
continue;


process(&lineptr, env);

i = 0;
}
    
free(lineptr);
return (0);
}
