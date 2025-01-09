#ifndef	MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>

int main(int argc, char *argv[], char *envp[]);
char *enter_shell(char *box);
int print_entry(void);
char *remove_newline(char *str);
char **token_separation(char *box);
int execute_command(char *argv[], char *envp[]);
char *find_command(char *command);
void print_environment(void);
void print_env(char **env);
int command_status(char *command);

#endif
