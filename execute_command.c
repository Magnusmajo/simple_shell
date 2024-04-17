#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int numChildren = 5;
	pid_t childPid;
	
	for (int i = 0; i < numChildren; i++) {
	childPid = fork();

	if (childPid < 0) {
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (childPid == 0) {
		// Child process
printf("Child %d (PID %d) executing ls -l /tmp:\n", i + 1, getpid());
	execl("/bin/ls", "ls", "-l", "/tmp", (char*)NULL);
	perror("execl failed"); // Print error if execl fails
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

