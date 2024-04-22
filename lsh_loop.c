#include "shell.h"

/**
 * lsh_loop - Create the principal bucle
 */
void lsh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> "); // Prompt
        line = lsh_read_line(); // Leer la línea de comandos
        args = lsh_split_line(line); // Dividir la línea en argumentos
        status = lsh_execute(args); // Ejecutar el comando
        free(line);
        free(args);
    } while (status);
}

