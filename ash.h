#ifndef ASH_H
#define ASH_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

// PROMPT
void prompt(void);

// INPUT/PROCESSING
void process_input(void);

// EXECUTING
void execute(char **argv);

#endif
