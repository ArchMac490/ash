#include "ash.h"

int main(void) {

  while (true) {
    // Print the prompt and process input
    prompt();

    // Read and execute program
    process_input();

    // Execute the command (if necessary)
    // execute(&command, &parameters);
  }

  return 0;
}
