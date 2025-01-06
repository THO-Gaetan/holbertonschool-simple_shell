#include "main.h"

/**
 * enter_shell - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int enter_shell(void)
{
	char *box = NULL;
	size_t n = 0;
	ssize_t ctrl_out;
	char *command_path = "/bin/ls";
	pid_t pid;
	char *argv[64];
	char *envp[] = {NULL};
	int i = 0;

	printf("Ardo@Gaetan:/My_Shell$ ");
	ctrl_out = getline(&box, &n, stdin);
	if (ctrl_out == -1)
	{
		free(box);
		printf("\n");
		exit_shell();
		exit(0);
	}
	box = remove_newline(box);

	if (strcmp(box, "exit") == 0)
	{
		free(box);
		exit_shell();
	}
	command_path = command(box);
	argv[i] = strtok(box, " ");
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	argv[i] = NULL;

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

	printf("%s\n", box);
	free(box);
	return (0);
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
