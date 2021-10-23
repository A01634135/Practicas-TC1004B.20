//Programa que no se puede matar con ctrl+c

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//Funcion para reemplazar cuando reciba señal
void handleTerm(int signal){
    printf("Recibí señal %d\b", signal);
}


int main(){
    
    signal(2, handleTerm); //registrar la señal

    while(1){
        printf("Trabajando \n");
        sleep(1); //para que no se sature la pantalla
    }

    return 0;
}