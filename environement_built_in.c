#include "main.h"
/**
 * print_environment - Prints the current environment
 *
 * Description: This function prints all environment variables
 * stored in the _environ array, one per line.
 */
void print_environment(void)
{
char **env = _environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
/**
 * main - Simple shell implementation
 *
 * Return: Always 0
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

while (1)
{
printf("$ ");
read = getline(&line, &len, stdin);

if (read == -1)
break;


line[strcspn(line, "\n")] = 0;

if (strcmp(line, "env") == 0)
{
print_environment();
}
else if (strcmp(line, "exit") == 0)
{
break;
}
else
{
printf("Command not found: %s\n", line);
}
}

free(line);
return (0);
}
