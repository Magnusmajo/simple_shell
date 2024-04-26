#include "shell.h"

int lsh_execute(char **args) {
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL) {
        return 1; 
    }
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "lsh: se esperaba un argumento para \"cd\"\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("lsh");
            }
        }
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0; 
    }

    pid = fork();
    if (pid == 0) {

        if (execvp(args[0], args) == -1) {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("lsh");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

