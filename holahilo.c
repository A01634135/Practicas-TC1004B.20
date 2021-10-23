#include <stdio.h>
#include <pthread.h>

//correrlo gcc -o holahilo holahilo.c -lpthread
// luego ./holahilo

//variables globales
#define NUM_THREADS 1000

int saldo;
pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER;

//Region critica
void * suma100(void *arg){
    int localsaldo;
    pthread_mutex_lock(&saldoLock);
    localsaldo = saldo;
    localsaldo += 100;
    saldo = localsaldo;
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);

}

int main(){

    //arreglo de direcciones de c/hilo
    pthread_t threads[NUM_THREADS];
    saldo = 0;

    for(int i = 0; i < NUM_THREADS; i ++){
        //pthread_create(&threads[i], NULL, printHola, NULL);
        pthread_create(&threads[i], NULL, suma100, NULL);
    }

    for(int i = 0; i < NUM_THREADS; i ++){
        pthread_join(threads[i], NULL); //hilos -> valor que quiero guardar de exit
    }

    printf("Saldo final %d\n", saldo);
    pthread_exit(NULL);
    
    return 0;
}