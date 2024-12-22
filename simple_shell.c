#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define BUFFER_SIZE 1024

/**
 * execute_command - Executes a command using execve
 * @command: The command to execute
 *
 * Return: 1 on success, -1 on failure
 */
int execute_command(char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("Fork failed");
return (-1);
}
else if (pid == 0)
{
char *args[] = {command, NULL};

if (execve(command, args, NULL) == -1)
{
perror("./simple_shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
return (1);
}

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char command[BUFFER_SIZE];

while (1)
{
printf(PROMPT);

if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n");
break;
}

command[strcspn(command, "\n")] = 0;

if (strlen(command) > 0)
{
execute_command(command);
}
}

return (0);
}
