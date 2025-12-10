#include "ash.h"

void reset_values(char *command, char *parameters) {
	memset(command, MAX_INPUT_LENGTH, MAX_INPUT_LENGTH);
  parameters = NULL;
}

void prompt(void) {
	printf("\n> ");
}

void read_input(char *command) {
  fgets(command, MAX_INPUT_LENGTH, stdin);
}

// TODO: Potential issues with whitespace?
// TODO: Potential issues with overflows?
void process_input(char **command, char **parameters) {
  *command = strtok(*command, " \n"); 
  *parameters = strtok(NULL, "\n");
}

void execute(char **command, char **parameters) {
  int status = 0;

  if (fork() != 0) { // Parent Process
    waitpid(-1, &status, 0);
  } else { // Child Process
    // TODO: Error checking
    // TODO: Environment variables
    execve(*command, parameters, environ);
  }
}
