#include "shell.h"
/**
 * main - Carga archivos de configuracion y ejecuta
 * el bucle principal
 */
int main(int argc, char **argv) {
    // Cargar archivos de configuración si los hubiera
    // Ejecutar el bucle principal
    lsh_loop();
    // Realizar cualquier limpieza o liberación de memoria necesaria
    return EXIT_SUCCESS;
}
