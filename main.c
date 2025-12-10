#include "ash.h"

int main(void) {
  char *command = malloc(MAX_INPUT_LENGTH * sizeof(char));
  char *parameters = NULL;

  while (true) {
    reset_values(command, parameters);

    prompt();
    read_input(command);
    process_input(&command, &parameters);
    printf("command: %s, parameters: %s", command, parameters);
    printf("envp: %s\n", environ[0]);

    execute(&command, &parameters);
  }

  return 0;
}
