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
	int status;

	while (1)
	{
		box = enter_shell(box);

		argv = token_separation(box);


		status = execute_command(argv);

		free(box);
		if (argv != NULL)
		{
			free(argv);
		}
		if (status == 127)
		{
			/* Handle error case*/
			continue;
		}
	}
	return (0);
}
