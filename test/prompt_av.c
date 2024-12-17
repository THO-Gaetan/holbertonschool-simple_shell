#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	char *box;
	char *input_copy;
	int i = 1;
	const char *separator = " ";

	if (ac < 2)
		return (1);
	while (i < ac)
	{
		input_copy = strdup(av[i]);
		box = strtok(input_copy, separator);
		while (box != NULL)
		{
			printf("%s\n", box);
			box = strtok(NULL, separator);
		}
		i++;
	}
	return (0);
}
