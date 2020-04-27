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


// 3. Write a hello client-server program in which server will reply: “Hello there!” if receiving “Hello!”, otherwise it will send: “You must say Hello!”

//./a.out 127.0.0.1 <string>
int main(){
    int listenfd, connfd, val;
    struct sockaddr_in servAddr;
    char buff[MAX];
    char* serverRepond = "You must say Hello!";
    char* serverRepondForCorrect = "Hello there!";
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
        if(strcmp(buff,"Hello!") != 0)
        {
            printf("%s\n",buff);
            send(connfd,serverRepond,strlen(serverRepond),0);
            printf("Some one not saying hello\n");
        }else{
            send(connfd,serverRepondForCorrect,strlen(serverRepondForCorrect),0);
            printf("Hello message sent:\n");
        }
        close(connfd);
    }
}