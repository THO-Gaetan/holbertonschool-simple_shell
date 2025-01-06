#include "main.h"

char **token_separation(char *box)
{
	int i = 0;
	char **argv;

	argv = malloc(64 * sizeof(char *));
	argv[i] = strtok(box, " ");
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}