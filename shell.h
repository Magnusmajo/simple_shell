#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_execute(char **args);
void lsh_setup_signals(void);
void lsh_loop(void);
#endif
