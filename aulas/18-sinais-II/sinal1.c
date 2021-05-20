#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int num_ctrl_c = 0;

void sig_handler(int num) {
    printf("Chamou Ctrl+C\n");
    num_ctrl_c++;
    if (num_ctrl_c > 2) {
        struct sigaction handler_sigint_dfl;
        handler_sigint_dfl.sa_handler = SIG_DFL;
        sigemptyset(&handler_sigint_dfl.sa_mask);
        handler_sigint_dfl.sa_flags = 0;

        sigaction(SIGINT, &handler_sigint_dfl, NULL);
        // exit(0);
    }
}

int main() {
    /* TODO: registre a função sig_handler
     * como handler do sinal SIGINT
     */

    struct sigaction handler_sigint;
    handler_sigint.sa_handler = sig_handler;
    sigemptyset(&handler_sigint.sa_mask);
    handler_sigint.sa_flags = 0;

    sigaction(SIGINT, &handler_sigint, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
