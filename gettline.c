#include <stdio.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    size_t bufsize = 0;
    ssize_t bytes_read;
    char *line = NULL;

    bytes_read = getline(&line, &bufsize, stream);
    if (bytes_read == -1) {
        free(line);
        return -1;
    }

    *lineptr = line;
    *n = bufsize;
    return bytes_read;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter a line of text: ");
    read = my_getline(&line, &len, stdin);

    if (read != -1) {
        printf("You entered: %s", line);
    } else {
        printf("Error reading input.\n");
    }

    free(line);
    return 0;
}
