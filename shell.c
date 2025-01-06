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
		enter_shell(box);

		argv = token_separation(box);

		execute_command(argv);
	}
	return (0);
}
