#include "shell.h"

/**
 * lsh_read_line - LEe las lineas de comando
 * Return: La linea
 */

char *lsh_read_line(void) {
	char *line = NULL;
	size_t bufsize = 0; // Tamaño inicial de la línea

	if (getline(&line, &bufsize, stdin) == -1) {
		perror("I'll back: getline");
		exit(EXIT_FAILURE);
	}
	return line;
}

