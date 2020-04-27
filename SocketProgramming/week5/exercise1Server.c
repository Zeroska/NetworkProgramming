#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#define MAX_LINE 100



int main(int argc, char ** argv){
    int listenfd, connfd;
    struct sockaddr_in servAddr;
    char buff[MAX_LINE];
    time_t ticks;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servAddr,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(13);
    bind(listenfd, (struct sockaddr *) &servAddr,sizeof(servAddr));
    listen(listenfd,100);
    for(;;){
        connfd = accept(listenfd, (struct sockaddr *) NULL, NULL);
        ticks = time(NULL);
        snprintf(buff,sizeof(buff), "%.24s\r\n",ctime(&ticks));
        write(connfd,buff,strlen(buff));
        close(connfd);
    }

}