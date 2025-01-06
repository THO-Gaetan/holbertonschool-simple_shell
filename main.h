#ifndef	MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int shell(void);
int enter_shell(void);
int exit_shell(void);
char *remove_newline(char *str);
char *command(char *box);


#endif
