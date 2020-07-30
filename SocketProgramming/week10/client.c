//1. Write a program to create a UDP connection in which server executes simple operations (+, -, *, /)
//2. Write a simple chat program using UDP connection.
//3. Write a UDP client/server program in which the server creates an nxm random matrix, with n&m are sent by the client, and then sends the sum of the first row to its client.
//       For example:
//Client sends: ì2 3î
//Server creates: 
//	ì4 12 7
// 9 20 15î ? sends: ìSum of the first row: 23î

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024
#define PORT 1337

char *fgetstr(char *string, int n, FILE *stream){
    char* result;
    result = fgets(string, n ,stream);
    if(!result){
        return result;
    }
    if(string[strlen(string) -1] == '\n'){
        string[strlen(string) -1] = 0;
    }
    return string;
}


int main(int argc, char *argv[]){
    int sockfd;
    struct sockaddr_in servAddr;
    char userInput[BUFSIZE] = {0};
    char serverResponse[BUFSIZE] = {0};
    if((sockfd = socket(AF_INET,SOCK_DGRAM, 0)) < 0){
        printf("[!] Something in socket() is wrong");
        exit(EXIT_FAILURE);
    }
    //set all the bits to zeros
    memset(&servAddr,0,sizeof servAddr);
    //seting up the file descriptor
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = INADDR_ANY;
    fgets(userInput, sizeof userInput,stdin);

    //UDP send 
    if(sendto(sockfd, userInput, BUFSIZE, 0, (struct sockaddr*) &servAddr, sizeof servAddr) < 0){
        printf("[!] Weird thing happened in sendto()\n SHUTDOWN");
    }
    //UDP recieve
    if(recvfrom(sockfd,serverResponse, BUFSIZE,0, (struct sockaddr*)NULL,NULL) < 0){
        printf("[!] Oh no can't recieve anything");
    }
    printf("[*] Server answer: %s\n",serverResponse);
    printf("[*] Exit ...\n");
    close(sockfd);
    return 0;
}
