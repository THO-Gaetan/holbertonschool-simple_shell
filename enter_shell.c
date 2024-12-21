#include "main.h"

int enter_shell(void)
{
	char *box = NULL;
	size_t n = 0;
	ssize_t ctrl_out;

	printf("Ardo@Gaetan:/My_Shell$ ");
	ctrl_out = getline(&box, &n, stdin);
	if (ctrl_out == -1)
	{
		free(box);
		printf("\nSortie du shell\n");
		exit(0);
	}
	box = remove_newline(box);

	if (strcmp(box, "exit") == 0)
	{
		free(box);
		exit_shell();
	}
	printf("%s\n", box);
	free(box);
	return (0);
}

int exit_shell(void)
{
	printf("Erreur dans le shell\nSortie du shell\n");
	exit(0);
}

char *remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
		i++;
	}
	return (str);
}
