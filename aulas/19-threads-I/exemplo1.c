
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i1, i2;
    int ret;
} args_t;

void *minha_thread(void *arg) {
    args_t *args = (args_t *) arg;
    printf("i1: %d i2: %d\n", args->i1, args->i2);
    args->ret = args->i2 + args->i1;
    return NULL;
}

int main() {
    pthread_t tids[4];
    args_t *args = malloc(sizeof(args_t) * 4);
    

    for (int i = 0; i < 4; i++) {
        args[i].i1 = i * 2;
        args[i].i2 = i * 3;
        pthread_create(&tids[i], NULL, minha_thread, &args[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
        printf("Ret: %d\n", args[i].ret);
    }

    free(args);
    
    return 0;
}
