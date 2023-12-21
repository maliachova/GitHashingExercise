#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function
void sigint_handler(int signal) {
    printf("SIGINT signal caught!\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // Registering the signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Signal registration failed");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to keep the program running
    while (1) {
        // Do nothing, waiting for SIGINT
    }

    return 0;
}

