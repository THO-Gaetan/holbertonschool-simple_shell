#include "main.h"
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *box = NULL;
	char **argv;

	while (1)
	{
		box = enter_shell(box);

		argv = token_separation(box);
		free(box);

		execute_command(argv);
		free(argv);
	}
	return (0);
}
