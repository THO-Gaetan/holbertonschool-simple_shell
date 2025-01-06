#include "main.h"

int execute_command(char **argv)
{
	char *command_path;
	pid_t pid;
	char *envp[] = {NULL};

	command_path = find_command(argv[0]);
	if (argv[0] != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(command_path, argv, envp) == -1)
			{
				perror("execve");
				free(argv);
				return (1);
			}
		}
		else if (pid > 0)
		{
			int status;

			waitpid(pid, &status, 0);
		}
		else
			perror("fork");
	}
	free(command_path);
	free(argv);
	return (0);
}