#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024
#define PORT 1337

int main(void){
    int connfd;
    char serverInput[BUFSIZE];
    char serverResponse[BUFSIZ];
    struct sockaddr_in servAdrr, cliAdrr;
    if ((connfd = socket(AF_INET,SOCK_DGRAM, 0)) < 0){
        perror("[!] Something wrong in socket()");
        exit(EXIT_FAILURE);
    }
    
}