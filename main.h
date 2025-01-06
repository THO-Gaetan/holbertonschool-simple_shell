#ifndef	MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int shell(void);
int enter_shell(char *box);
int exit_shell(void);
char *remove_newline(char *str);
char **token_separation(char *box);
int execute_command(char **argv);
char *find_command(const char *command);

#endif
