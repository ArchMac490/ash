#include "ash.h"

int main(void) {
  while (true) {
    // Print the prompt and process input
    prompt();

    // Read and execute program
    char **argv = process_input();

    // TODO: Check for input errors
    if (argv == NULL) {
      break;
    }

    // Execute the program
    execute(argv);
  }

  return 0;
}
