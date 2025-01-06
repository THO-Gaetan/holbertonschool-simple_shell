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
    printf(PROMPT);
    fflush(stdout);
}

/**
 * main - Point d'entrée du programme shell
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];
    char *args[2];
    pid_t pid;

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

        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            args[0] = command;
            args[1] = NULL;

            if (execve(command, args, NULL) == -1)
            {
                printf("./shell: No such file or directory\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }

    return (0);
}
