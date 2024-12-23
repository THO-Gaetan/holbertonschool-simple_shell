#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 64

/**
 * read_command - Reads a command from standard input.
 *
 * Return: Pointer to the command string or NULL on failure.
 */
char *read_command(void)
{
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t len = getline(&command, &bufsize, stdin);

    if (len == -1) {
        return NULL;
    }

    command[strcspn(command, "\n")] = 0;
    return command;
}

/**
 * execute - Executes a given command.
 * @command: The command to execute.
 *
 * Return: 1 on success, otherwise 0.
 */
int execute(char *command)
{
    pid_t pid, wait_pid;
    int status;

    pid = fork();

    if (pid == 0) {
        char *args[] = {command, NULL};
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "./simple_shell: %s: No such file or directory\n", command);
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error creating child process");
    } else {
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/**
 * main - Entry point of the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *command;
    int status;

    do {
        printf("#cisfun$ ");
        command = read_command();

        if (command == NULL) {
            free(command);
            exit(0);
        }

        status = execute(command);
        free(command);
    } while (status);

    return 0;
}
