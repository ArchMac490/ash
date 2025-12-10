#include "ash.h"

void prompt(void) { printf("\n> "); }

char **process_input(void) {
  // Declare buffers
  char *buff = NULL;
  size_t buff_size = 0;

  // Read input
  ssize_t len = getline(&buff, &buff_size, stdin);

  // If EOF is read, end the program
  if (len == EOF) {
    printf("EOF'd\n");
    free(buff); // is this necessary?
    return NULL;
  }

  // Scan for how many elements then allocate instead of using realloc
  size_t terms = 0;
  for (int i = 1; i < strlen(buff); i++) {
    if (isspace(buff[i]) && !isspace(buff[i - 1])) {
      terms += 1;
    }
  }

  // Create an array of whitespace delimited, NULL terminated strings
  char **argv = calloc(terms + 1, sizeof(char *));
  char *token = NULL;
  size_t term_index = 0;

  // Separate terms by whitespace, moving them into argv
  token = strtok(buff, " \t\n");
  while (token != NULL) {
    argv[term_index++] = strdup(token);
    token = strtok(NULL, " \t\n");
  }

  // Append a NULL to the array
  argv[term_index] = NULL;

  // Free the original buffer
  free(buff); // TODO: Check if this causes a memory leak

  return argv;
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

  // Free all strings in argv, then argv
  size_t i = 0;
  while (argv[i] != NULL) {
    free(argv[i++]);
  }
  free(argv);
}
