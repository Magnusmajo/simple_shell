#include "shell.h"
#include <signal.h>

void handle_sigint(int signo) {
    printf("\nSe presionó Ctrl+C. No se puede interrumpir la shell.\n");
}

void lsh_setup_signals(void) {
    signal(SIGINT, handle_sigint);
}
