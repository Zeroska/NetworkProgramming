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

//./a.out 127.0.0.1 <string>
int main(){
    int listenfd, connfd, val;
    struct sockaddr_in servAddr;
    char buff[MAX + 1];
    char serverRepond[MAX];
    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servAddr,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(80);
    bind(listenfd, (struct sockaddr *) &servAddr,sizeof(servAddr));
    listen(listenfd,100);
    for(;;){
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        val = read(connfd,buff,MAX);
        printf("%s\n",buff);
        int len = strlen(buff);
        int count = 0;
        for (int i = 0;i < len;i++){
            if(buff[i] != ' ' && buff[i + 1] == ' '){
                count += 1;
            }
        }
        sprintf(serverRepond,"%d",count);
        send(connfd,serverRepond,strlen(serverRepond),0);
        printf("message sent: %s\n",serverRepond);
        //Zero out the memory for next socket
        //last time I havent zero out the buffer so thing was litte messy
        memset(serverRepond,0,strlen(serverRepond));
        memset(buff,0,strlen(buff));
        close(connfd);
        count = 0;
        
    }
}