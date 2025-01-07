#include "main.h"

#define MAX_TOKENS 64
/**
 * token_separation - start of the separation function
 * @box : user given string
 * Return: Always 0 (Success)
 */
char **token_separation(char *box)
{
	int i = 0;
	char **argv;

	argv = malloc(64 * sizeof(char *));
	if (argv == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}
	argv[i] = strtok(box, " ");
	while (argv[i] != NULL && i < MAX_TOKENS - 1)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}
