#include "main.h"

/**
 *print_env- prints the environmental variable using environ
 *Return: 0 - success
 */

int print_env(void)
{
char **env_var = environ;
int i = 0, j = 0;

while (env_var[i] != NULL)
{
j = 0;
while (env_var[i][j] != '\0')
{
if (_putchar(env_var[i][j]))
j++;
else
perror("Error printing variable");
}
_putchar('\n');
i++;

}
return (0);
}
