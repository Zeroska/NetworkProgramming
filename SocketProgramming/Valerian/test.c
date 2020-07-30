#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT "3490"
#define BACKLOG 10

void  sigchld_handler(int s){
    int saved_errno = errno;
    while(waitpid(-1,NULL,WNOHANG)>0);
    errno = saved_errno;
}

void* get_in_addr(struct sockaddr *sa)
{
    if(sa->sa_family == AF_INET){
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
     return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


//Stream server
int main(int argc, char *argv[]){
    int sockd, new_fd;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;
    socklen_t sin_size;
    struct sigaction sa;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;

    memset(&hints,0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; //use my IP

    if((rv = getaddrinfo(NULL,PORT,&hints, &servinfo))!=0){
        fprintf(stderr,"getaddrinfor: %s\n",gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p != NULL; p->ai_next){
        if((sockd = socket(p->ai_family, p->ai_socktype,p->ai_protocol))==-1){
            perror("server :socket");
            continue;
        }
        if(setsockopt(sockd,SOL_SOCKET,SO_REUSEADDR,&yes, sizeof(int))==-1){
            perror("setsockopt");
            exit(1);
        }
        
    }



}