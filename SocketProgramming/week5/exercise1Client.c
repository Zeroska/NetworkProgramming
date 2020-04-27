
#include "stdio.h"
#include "stdlib.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "strings.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAX_LINE 100
//Day time 
int main(int argc, char **argv){
    int sockfd , n; 
    char recvline[MAX_LINE + 1];
    struct sockaddr_in servAddr;
    if(argc != 2){
        printf("usage: ./daytimeO <IP_ADRESS>\n");
        exit(0);
    }
    if ((sockfd=socket(AF_INET,SOCK_STREAM,0)) <0){
        printf("socket error\n");
        exit(0);
    }
    bzero(&servAddr,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(13);
    if (inet_pton(AF_INET,argv[1],&servAddr.sin_addr) <= 0){
        printf("Error in inet_pton");
        exit(0);
    }
    if (connect(sockfd,(struct sockaddr *) &servAddr ,sizeof(servAddr))<0){
        printf("Errr in connect");
        exit(0);
    }

    while((n = read(sockfd,recvline,MAX_LINE))>0){
        recvline[n]  =0;
        if(fputs(recvline,stdout) == EOF){
            printf("fput err");
            exit(0);
        }
    }
    if(n < 0){
        printf("Dud");
    }
    exit(0);
}
