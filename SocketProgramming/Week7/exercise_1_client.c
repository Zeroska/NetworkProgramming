#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include "regex.h"

#define MAX 1024

//If client send a string will it easier to process
int main(int argc, char **argv){
    int clientSock,n;
    char buffer[MAX];
    struct sockaddr_in serverSockAddr;
    if(argc != 2){
        printf("Usage: execise_1_client.c  1+1");
        exit(0);
    }
    if((clientSock = socket(AF_INET,SOCK_STREAM,0))< 0){
        printf("socket error");
        exit(0);
    }
    bzero(&serverSockAddr,sizeof(serverSockAddr));
    serverSockAddr.sin_family = AF_INET;
    serverSockAddr.sin_addr.s_addr = INADDR_ANY;
    serverSockAddr.sin_port = htons(80);
    if(connect(clientSock,(struct sockaddr*)&serverSockAddr,sizeof(serverSockAddr))<0){
        printf("Err in connect");
        exit(0);
    }
    // how to send an array
    send(clientSock,argv[1],strlen(argv[1]),0); 
    printf("%s\n",argv[1]);
    printf("message sent\n");
    n = read(clientSock,buffer,MAX);
    printf("[Server] Respond: %s\n",buffer);
    memset(buffer,0,strlen(buffer));
}