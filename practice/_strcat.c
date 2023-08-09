#include "main.h"
/**
 *_strcat- concatenates two strings
 *@s1: buffer to concatenate to
 *@s2: buffer to concatenate from
 *Return: pointer to concatenated string
 */

char *_strcat(char *s1, const char *s2)
{
int i = 0, j = 0;

while (s1[i] != '\0')
i++;

while (s2[j] != '\0')
{
s1[i] = s2[j];
i++;
j++;
}

s1[i] = '\0';

return (s1);
}
