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



int main(){
    int listenfd, connfd, val;
    struct sockaddr_in servAddr;
    char buff[MAX];
    char* serverRepond[MAX];
    char* serverRepondForCorrect = "I'm ready to help you";
    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servAddr,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY; //127.0.0.1 will be the best 
    servAddr.sin_port = htons(80);
    bind(listenfd, (struct sockaddr *) &servAddr,sizeof(servAddr));
    listen(listenfd,100);
    for(;;){
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        val = read(connfd,buff,MAX);
        printf("%s",buff);
        int number = atoi(buff);
        printf("%d",number);
        // array to store binary number 
        int binaryNum[32]; 
        // counter for binary array 
        int i = 0;
         
        while (number > 0) { 
        // storing remainder in binary array 
            binaryNum[i] = number % 2; 
            number = number / 2; 
            i++; 
            printf("%d",binaryNum[i]);
        }
        printf("Hello");

        send(connfd,binaryNum,sizeof(binaryNum),0);
        //swap decimal to binary
        //Like you could use something like a function

        memset(buff,0,strlen(buff));
        
        close(connfd);
    }
}