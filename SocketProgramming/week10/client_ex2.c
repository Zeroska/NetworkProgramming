#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define BUFMAX 1024

int main(int argc, char *argv[]){
    int sockfd;
    struct sockaddr_in servAddr; 
    char userInput[BUFMAX];
    char serverResponse[BUFMAX];

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("[! Something wrong in the socket()");
        exit(EXIT_FAILURE);
    }
    memset(&servAddr, 0, sizeof servAddr);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(1337);
    servAddr.sin_addr.s_addr = INADDR_ANY;
    while(1){
        memset(userInput, 0 , sizeof userInput);
        memset(serverResponse, 0 , sizeof serverResponse);

        fgets(userInput, BUFMAX, stdin);
        sendto(sockfd, userInput, BUFMAX, 0, (struct sockaddr *)&servAddr, sizeof servAddr);
        recvfrom(sockfd, serverResponse, BUFMAX,0, (struct sockaddr *)&servAddr, sizeof servAddr );
        fprintf(stdout, "Server said: %s", serverResponse);
        if(strcmp(userInput, "!exit") == 0){
            break;
        }
    }
    printf("Exit!\n");
    close(sockfd);
    return 0;
}