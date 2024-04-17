#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    char* command;

    while (1) {
        printf("#cisfun$ "); // Print the shell prompt

        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle Ctrl+D (EOF)
            printf("\nExiting shell.\n");
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Execute the command
        command = input;
        pid_t childPid = fork();

        if (childPid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (childPid == 0) {
            // Child process
            execl(command, command, (char*)NULL);
            perror("execl failed"); // Print error if execl fails
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL); // Wait for the child to exit
        }
    }

    return 0;
}

