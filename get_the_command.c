#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * find_command - Searches for a command in /usr/bin/
 * @command: The name of the command to search for
 *
 * Return: A dynamically allocated string with the full path if found,
 *         NULL otherwise
 */
char *find_command(char *command)
{
	char path[256];

	if (command == NULL)
		return (NULL);
	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}
	snprintf(path, sizeof(path), "/bin/%s", command);

	if (access(path, X_OK) == 0)
		return (strdup(path));

	return (NULL);
}
