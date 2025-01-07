#include "main.h"
/**
 * print_environment - Prints the current environment
 *
 * Description: This function prints all environment variables
 * stored in the _environ array, one per line.
 */
void print_environment(void)
{
char **env = __environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
