#if defined (_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x06000
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif

// this allow some structure to it 
int main(){
    printf("[*] Configuring local address ... \n");
    struct addrinfo hints;
    memset(&hints, 0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    struct addrinfo *bind_address;
    getaddrinfo(0,"8080",&hints,&bind_address);

}