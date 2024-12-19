#include "main.h"

#define MAX_CMD_LENGHT 1024

int shell(void)
{
	char *box;
	size_t n = MAX_CMD_LENGHT;

	while (strcmp(box, "exit") != 0)
	{
		printf("Ardo@Gaetan:My_Shell$ ");
		getline(&box, &n, stdin);
		printf("%s", box);
	}
	return (0);
}
