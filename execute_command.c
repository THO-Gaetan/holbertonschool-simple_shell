#include "main.h"
/**
 * execute_command - Entry point the execution function
 * @argv : the tokenisen string that the user enter.
 * Return: Always 0 (Success)
 */
int execute_command(char **argv)
{
	char *command_path;
	pid_t pid;
	char *envp[] = {NULL};
	int result;
	int status;

	status = command_status(argv[0]);
	if (status == 127)
		return (status);
	command_path = find_command(argv[0]);
	if (argv[0] != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			return (1);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(command_path, argv, envp) == -1)
			{
				perror("execve");
				free(command_path);
				return (-1);
			}
		}
		else
			wait(&result);

	}
	free(command_path);
	return (0);
}
