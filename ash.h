#ifndef ASH_H
#define ASH_H

#define MAX_INPUT_LENGTH 32

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

// HELPERS
void reset_values(char *command, char *parameters);

// PROMPT
void prompt(void);

// INPUT/PROCESSING
void read_input(char *command);
void process_input(char **command, char **parameters);

// EXECUTING
void execute(char **command, char **parameters);

#endif
