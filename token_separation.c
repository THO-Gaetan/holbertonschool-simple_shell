#include "main.h"

#define MAX_TOKENS 64
char **token_separation(char *box)
{
	int i = 0;
	char **argv;

	argv = malloc(64 * sizeof(char *));
	if (argv == NULL)
	{
		perror("malloc failed");
		free(argv);
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
