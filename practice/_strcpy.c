#include "main.h"
/**
 *_strcpy- copies string from source into destination
 *@dest: buffer to be copied into
 *@src: buffer to be copied from
 *Return: pointer to the copied string
 *or NULL if it fails
 */

char *_strcpy(char *dest, const char *src)
{

char *result = dest;

if (dest == NULL)
return (NULL);

while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';

return (result);
}
