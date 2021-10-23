#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();

    if (pid == 0){
        close (0); //cerrar entrada estandar
        dup(fd[0]); //cerrar entrada pipe
        close(fd[1]); //cerrar salida pipe
        execlp("wc", "wc", "-l", NULL); // conectar entrada pipe

    } else {
        close (1); //cerrar salida estándar
        dup(fd[1]); //cerrar salida pipe
        close(fd[0]); //cerrar entrada pipe
        execlp("ls", "ls", NULL); // conectar salida ls a pipe
    }

    return 0;
}