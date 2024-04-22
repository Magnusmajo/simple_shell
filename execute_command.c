#include "shell.h"

int lsh_execute(char **args) {
    pid_t pid, wpid;
    int status;

    // Comandos internos
    if (args[0] == NULL) {
        return 1; // No se ingresó ningún comando
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
        return 0; // Salir de la shell
    }

    // Comandos externos
    pid = fork();
    if (pid == 0) {
        // Proceso hijo
        if (execvp(args[0], args) == -1) {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error al crear el proceso hijo
        perror("lsh");
    } else {
        // Proceso padre
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

