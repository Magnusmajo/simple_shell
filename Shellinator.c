#include "shell.h"

#define MAX_INPUT_LENGTH 100

int main()
{
	char input[MAX_INPUT_LENGTH];
	char* command = "$ ";

	while (1)
	{
		printf("#shelinator %s", command); // Print the shell prompt

	if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle Ctrl+D (End of file detected)
		printf("\nBye Bye\n");
		break;
	}

        // Remove newline character from input
	input[strlen(input) - 1] = '\0';

	 // Check if the command is"exit" to end the shell
	if (strcmp(input, "exit") == 0)
	{
		printf("Bye Bye...\n");
		break;
	}
	
	// Execute the command
	command = input;
	pid_t childPid = fork();

	if (childPid < 0)
	{
		perror("Ups fork failed"); //Print error if fork fail
		exit(EXIT_FAILURE);
	}
	else if (childPid == 0)
	{
            // Child process
		execl(command, command, (char*)NULL);
		perror("Ups execl failed"); // Print error if execl fails
		exit(EXIT_FAILURE);
	}
	else
		{
		// Parent process
			wait(NULL); // Wait for the child to exit
		}
	}

    return 0;
}

