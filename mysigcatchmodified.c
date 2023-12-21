#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int sigint_count = 0;

void custom_signal_handler(int signum) {
    // Display signal number and a message
    printf("Custom handler: Caught signal %d (SIGINT)\n", signum);

    // Increment the count
    sigint_count++;

    // Check if SIGINT has been caught twice
    if (sigint_count == 2) {
        // Restore the default behavior for SIGINT
        signal(SIGINT, SIG_DFL);
        printf("Restored default handler for SIGINT\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    // Register custom signal handler for SIGINT
    if (signal(SIGINT, custom_signal_handler) == SIG_ERR) {
        fprintf(stderr, "Unable to register signal handler\n");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to keep the program running
    while (1) {
        // Do nothing, waiting for SIGINT
    }

    return 0;  // This line is never reached
}
