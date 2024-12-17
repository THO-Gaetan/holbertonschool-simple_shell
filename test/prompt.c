#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *box;
	size_t n = 10;

	box = malloc(sizeof(char) * n);
	if (box == NULL)
		return (0);
	printf("$ ");
	getline(&box, &n, stdin);
	printf("%s\n", box);
	return (0);
}
