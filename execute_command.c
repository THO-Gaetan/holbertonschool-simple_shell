#include "main.h"
/**
 * execute_command - Entry point the execution function
 * @argv : the tokenisen string that the user enter.
 * Return: Always 0 (Success)
 */
int execute_command(char *argv[], char *envp[])
{
	char *command_path;
	pid_t pid;
	int result;
	int status;

	status = command_status(argv[0]);
	if (status == 127)
		return (status);
	command_path = find_command(argv[0]);
	if (command_path == NULL)
		return (1);
	if (strcmp(argv[0], "env") == 0)
	{
		print_env(envp);
		free(command_path);
		return (0);
	}
	if (argv[0] != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			free(command_path);
			return (1);
		}
		if (pid == 0)
		{
			if (execve(command_path, argv, envp) == -1)
			{
				perror("execve");
				free(command_path);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&result);

	}
	free(command_path);
	return (0);
}
