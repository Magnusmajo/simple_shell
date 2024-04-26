#include "shell.h"

/**
 * lsh_loop - Create the principal bucle
 */
void lsh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
		printf("Shellinator$> "); /*Prompt*/
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args); 
		free(line);
		free(args);
    } while (status);
}

