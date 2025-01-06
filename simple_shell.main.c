#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define PROMPT "#cisfun$ "

/**
 * display_prompt - Affiche le prompt du shell
 *
 * Cette fonction affiche le prompt défini et vide le buffer de sortie.
 */
void display_prompt(void)
{
	printf("%s", PROMPT);
	fflush(stdout);
}

/**
 * execute_command - Exécute la commande donnée
 * @command: La commande à exécuter
 *
 * Return: 0 en cas de succès, -1 en cas d'échec
 */
int execute_command(char *command)
{
	pid_t pid;
	char *args[2];

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;
		if (execve(command, args, environ) == -1)
		{
			printf("%s: No such file or directory\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * main - Point d'entrée du programme shell
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
			continue;

		if (execute_command(command) == -1)
			break;
	}

	return (0);
}
