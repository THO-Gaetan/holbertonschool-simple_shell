#include "main.h"
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char *envp[])
{
	char *box = NULL;
	int status;

	if (argc == 0)
		return (0);
	while (1)
	{
		box = enter_shell(box);

		argv = token_separation(box);


		status = execute_command(argv, envp);

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
