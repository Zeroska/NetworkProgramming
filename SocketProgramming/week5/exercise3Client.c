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
// 1. Write a daytime server-client program

// 2. Write a program in which server sends back whatever it has received 
// For example: Client sends: “Hello!”
//   --> Server replies: “Hello!”
  
// 3. Write a hello client-server program in which server will reply: “Hello there!” if receiving “Hello!”, otherwise it will send: “You must say Hello!”

int main(int argc, char ** argv){
    int sockfd, n;
    char buffer[MAX];
    struct sockaddr_in servAddr;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
     if ((sockfd=socket(AF_INET,SOCK_STREAM,0)) <0){
        printf("socket error\n");
        exit(0);
    }
    bzero(&servAddr,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(80);
    if(inet_pton(AF_INET,argv[1],&servAddr.sin_addr) <=0){
        printf("Error");
        exit(0);
    }
    if(connect(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0){
        printf("connection failed");
        exit(0);
    }
    send(sockfd,argv[2],strlen(argv[2]),0);
    printf("Message sent\n");
    n = read(sockfd,buffer,MAX);
    printf("%s\n",buffer);
}