#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Parent process ID: %d\n", getppid());
    }
    return 0;
}
