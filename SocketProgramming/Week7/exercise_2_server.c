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

char *removeBlanks(const char *str)
{
    int i, j;
    char *newString;
    newString = (char *)malloc(MAX);
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        /* If blank space is found */
        if (str[i] == ' ')
        {
            newString[j] = ' ';
            j++;
            /* Skip all consecutive spaces */
            while (str[i] == ' ')
                i++;
        }
        newString[j] = str[i];
        i++;
        j++;
    }
    // NULL terminate the new string
    newString[j] = '\0';
    return newString;
}

int main()
{
    int listenfd, connfd, val;
    struct sockaddr_in servAddr;

    char serverRepond[MAX];
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(80);
    bind(listenfd, (struct sockaddr *)&servAddr, sizeof(servAddr));
    listen(listenfd, 100);
    for (;;)
    {
        char buff[MAX + 1];
        connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
        val = read(connfd, buff, MAX);

        printf("%s\n", buff);
        //clear the redundant space in string
        // int len = strlen(buff);
        // int count = 0;
        // for (int i = 0;i < len;i++){
        //    if(buff[i] == 'x' || buff[i] == 'X'){
        //        count += 1;
        //    }
        char * respond = removeBlanks(buff);
        sprintf(serverRepond, "%s", respond);
        send(connfd, serverRepond, strlen(serverRepond), 0);
        printf("message sent:%s\n", serverRepond);
        //Zero out the memory for next socket
        //last time I havent zero out the buffer so thing was litte messy
        //This time is a big mess on exercise one =))) yezzzzzzzzzz
        memset(serverRepond, 0, strlen(serverRepond));
        close(connfd);
    }
}