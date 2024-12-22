#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * read_command - Reads a command from standard input
 *
 * Return: The command entered by the user
 */
char *read_command(void)
{
char *command = NULL;
ssize_t buf = 0;

if (getline(&command, &buf, stdin) == -1)
{
free(command);
return (NULL);
}
return (command);
}

/**
 * execute_command - Executes a command using execvp
 * @command: The command to execute
 *
 * Return: 1 on success, -1 on failure
 */
int execute_command(char *command)
{
pid_t pid = fork();

if (pid == 0)
{
char *args[] = {command, NULL};
if (execvp(args[0], args) == -1)
{
perror("./simple_shell");
        }
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Fork failed");
return (-1);
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
char *command;

while (1)
{
printf("#cisfun$ ");

command = read_command();

if (command == NULL)
{
break;
}

command[strcspn(command, "\n")]

if (strlen(command) > 0)
{
execute_command(command);
}

free(command);
}

return (0);
}
