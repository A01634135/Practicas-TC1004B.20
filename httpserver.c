// gcc -o httpserver httpserver.c
// ./httpserver
// open on browser

#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

int main(){

    struct sockaddr_in serverAddress;
   
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2727); //decide cuál es el puerto
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); //se asocia a cualquier dirección ip asociada de la compu

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    bind(sockfd,(const struct sockaddr *)&serverAddress,sizeof(serverAddress)); //atiende peticiones
    //escuchando(sock, tamaño máximo de clientes en espera (atienes 1, esperan 4))
    listen(sockfd,5);

    while(1){
        struct sockaddr_in clientAddress;
        int clientSize = sizeof( clientAddress);
        //duerme el hilo principal hasta que llegue un cliente
        int clientSocket = accept(sockfd, (struct sockaddr *)&clientAddress,(unsigned int*) &clientSize);
        //protocolo
        char c;
        char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=ISO-8859-1\n\n   Hello desde gitpod"; //mensaje de respuesta. cabecera
        write(clientSocket,message,strlen(message));
        close(clientSocket);
    }
}