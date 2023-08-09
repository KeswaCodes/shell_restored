#include "main.h"
/**
 *error_message- prints an error message to stdout
 *Return: void
 */

void error_message(char *program)
{
  perror(program);
}
