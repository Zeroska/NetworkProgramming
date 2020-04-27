#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#define MAX 1024

// 1. Write a client-server program to do the following actions:
// - Client sends a string
// - Server replies the number of words in that string

// 2. Write a client-server program to do the following actions:
// - Client sends a string
// - Server replies the number of occurrences of character ‘x’ in that string


int main(int argc, char **argv){
    int clientSock, n;
    char RECV_LINE[MAX +1];
    struct sockaddr_in serverSockAddr;
    char buffer[MAX];
    if(argc != 2){
        printf("exercise_1_client <string you want to enter>\n");
        exit(0);
    }

    if((clientSock = socket(AF_INET,SOCK_STREAM,0))< 0){
        printf("socket error");
        exit(0);
    }
    bzero(&serverSockAddr,sizeof(serverSockAddr));
    serverSockAddr.sin_family = AF_INET;
    serverSockAddr.sin_port = htons(80);
    serverSockAddr.sin_addr.s_addr = INADDR_ANY; 
    if(connect(clientSock,(struct sockaddr*)&serverSockAddr,sizeof(serverSockAddr))<0){
        printf("Err in connect");
        exit(0);
    }
    send(clientSock,argv[1],strlen(argv[1]),0);
    printf("Message sent: %s\n", argv[1]);
    n = read(clientSock,buffer,MAX);
    printf("Character x ocurrence: %s\n",buffer);

}