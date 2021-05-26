#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct soma_parcial_args {
    double *vetor;
    int start, end;
    pthread_mutex_t *mutex_soma;
};

double soma = 0;
void *soma_parcial(void *_arg) {
    struct soma_parcial_args *spa = _arg;

    double local_soma = 0;
    for (int i = spa->start; i < spa->end; i++) {
        local_soma += spa->vetor[i]; 
    }
    pthread_mutex_lock(spa->mutex_soma);
    soma += local_soma; // REGIÃO CRÌTICA
    pthread_mutex_unlock(spa->mutex_soma);
    

    return NULL;
}

double soma_sequencial(double *vetor, int N) {
    double soma = 0;
    for (int i = 0; i < N; i++) {
        soma += vetor[i];
    }
    return soma;
}

int main(int argc, char *argv[]) {
    double *vetor = NULL;
    int n;
    scanf("%d", &n);

    vetor = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
    }

#ifdef SEQ
    printf("Sequencial: %lf\n", soma_sequencial(vetor, n));
#else
    pthread_t *tids = malloc(sizeof(pthread_t) * 4);
    struct soma_parcial_args *args = malloc(sizeof(struct soma_parcial_args) * 4);
    pthread_mutex_t mutex_soma = PTHREAD_MUTEX_INITIALIZER;

    for (int i = 0; i < 4; i++) {
        args[i].vetor = vetor;
        args[i].start = i * n / 4;
        args[i].end = (i + 1) * n / 4;
        args[i].mutex_soma = &mutex_soma;
        if (i == 3) args[i].end = n;

        pthread_create(&tids[i], NULL, soma_parcial, &args[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
    }

    free(tids);
    free(args);

    printf("Paralela: %lf\n", soma);

#endif
    /* TODO: criar thread_t e soma_parcial_args aqui */
    
    return 0;
}
