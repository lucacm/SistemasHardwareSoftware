#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("PID do filho: %d\n", getpid());
        while (1);
        
    } else {
        pid_t pid_terminou;
        int ws;

        pid_terminou = wait(&ws);

        printf("O meu filho de PID %d terminou!\n", pid_terminou);
        printf("Algumas infos sobre a finalização do processo filho:\n");
        printf("EXIT %d\nSGINALED %d\nSIGTERM %d\n", WIFEXITED(ws), WIFSIGNALED(ws), WTERMSIG(ws));
        printf("Sinal recebido pelo filho: %s\n", strsignal(WTERMSIG(ws)));
    }

    return 0;
}