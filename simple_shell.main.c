#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void prompt()
{
	printf("$ ");
}

int main()
{
	char *line = NULL;

	size_t len = 0;
	ssize_t read;
	pid_t pid;

	while (1)
	{
		prompt();
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			free(line);
			exit(0);
		}

		line[strcspn(line, "\n")] = 0;

		if (strcmp(line, "") == 0)
		{
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork failed");
			free(line);
			exit(1);
		}

		if (pid == 0)
		{
			char *argv[] = {line, NULL};

			if (execve(line, argv, NULL) == -1)
			{
				perror("Error executing command");
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	free(line);
	return (0);
}
