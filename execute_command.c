#include "main.h"

int execute_command(char **argv)
{
	char *command_path = "/usr/bin/";
	pid_t pid;
	char *envp[] = {NULL};

	if (argv[0] != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(command_path, argv, envp) == -1)
			{
				perror("execve");
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
	return (0);
}