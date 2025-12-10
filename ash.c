#include "ash.h"

void prompt(void) { printf("\n> "); }

void process_input(void) {
  // Declare buffers
  char *buff = NULL;
  size_t buff_size = 0;

  // Read input
  ssize_t len = getline(&buff, &buff_size, stdin);

  // FIX: Fix this, won't cancel program operation
  if (len == EOF) {
    free(buff);
    return;
  }

  // Create an array of whitespace delimited, NULL terminated strings
  char **argv = NULL;
  char *token = NULL;

  token = strtok(buff, " \t\n");
  size_t argv_len = 1;

  while (token != NULL) {
    argv = realloc(argv, (argv_len + 1) * sizeof(char *));
    argv[argv_len++ - 1] = strdup(token);
    token = strtok(NULL, " \t\n");
  }

  // Append a NULL to the array
  argv = realloc(argv, (argv_len + 1) * sizeof(char *));
  argv[argv_len] = NULL;

  // Free the original buffer
  free(buff); // TODO: Check if this causes a memory leak

  // Execute
  execute(argv);

  // Free all strings in argv, then argv
  size_t i = 0;
  while (argv[i] != NULL) {
    free(argv[i]);
  }
  free(argv);
}

void execute(char **argv) {
  int status = 0;

  if (fork() != 0) { // Parent Process
    waitpid(-1, &status, 0);
  } else { // Child Process
    // TODO: Error checking
    // TODO: Environment variables
    execve(argv[0], argv, environ);
  }
}
