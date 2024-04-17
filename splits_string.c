#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para dividir una cadena en palabras
void splitString(const char* inputString) {
    char* copyString = strdup(inputString); // Usamos strdup para copiar la cadena

    if (copyString == NULL) {
        printf("Error\n");
        return;
    }

    char* token = strtok(copyString, " "); // El espacio es el delimitador

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " "); // Siguiente palabra
    }

    free(copyString); // Liberamos la memoria asignada
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("%s\n", argv[0]);
        return 1; // Salir con código de error
    }

    const char* input = argv[1];
    splitString(input);

    return 0;
}
