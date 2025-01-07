#include "main.h"

/**
 * enter_shell - Entry point of the program
 * @box : user given string
 * Return: Always 0 (Success)
 */
char *enter_shell(char *box)
{
	size_t n = 0;
	ssize_t ctrl_out = 0;

	if (isatty(fileno(stdin)))
		print_entry();
	ctrl_out = getline(&box, &n, stdin);
	if (ctrl_out == -1)
	{
		if (isatty(fileno(stdin)))
			printf("\n");
		free(box);
		exit(0);
	}
	box = remove_newline(box);

	if (strcmp(box, "exit") == 0)
	{
		free(box);
		exit_shell();
	}
	return (box);
}
/**
 * exit_shell - exit point of the program
 *
 * Return: Always 0 (Success)
 */
int exit_shell(void)
{
	printf("exit\n");
	exit(0);
}
/**
 * remove_newline - remove newline to NULL terminaison
 * @str : the string that need to be changed
 * Return: Always 0 (Success)
 */
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
