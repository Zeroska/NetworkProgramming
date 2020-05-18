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

//shoudl return the total 
int calculator(int operand1, int operand2, char *operator){
    int total = 0;
    if (strcmp(operator,"+") == 0){
        total = operand1 + operand2;
    }else if(strcmp(operator,"-") == 0){
        total = operand1 - operand2;
    }else if(strcmp(operator,"*") == 0){
        total = operand1 * operand2;
    }else if(strcmp(operator,"/") == 0){
        total = operand1 / operand2;
    }else{
        printf("Err no operator\n");
    }
    return total;
}

char* findOperator(char string[], int lenght)
{
    char* key;
    for (int i = 0; i < lenght; i++){
        if (string[i] =='+')
        {
            key = "+";
        } else if(string[i] =='/'){
            key = "/";
        } else if (string[i] == '-'){
            key = "-";
        }else if (string[i] == '*'){
            key= "*";
        }
    }
    return key;
}

int main(){
    int listenfd, connfd, val;
    struct sockaddr_in servAddr;
    
    char serverRepond[MAX];
    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servAddr,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(80);
    bind(listenfd, (struct sockaddr *) &servAddr,sizeof(servAddr));
    listen(listenfd,100);
    printf("[Server is running]!\n");
    for(;;){
        char buff[MAX + 1];
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        val = read(connfd,buff,MAX);
        printf("[Client] send %s\n",buff);
        char * operator = findOperator(buff,strlen(buff));
        char * token = strtok(buff,operator);
        int array[2] = {0};
        int j = 0;
        //maybe the problem lie on the strtok (I read in the documentation, it is unsafe for thread and rentrant)
        while(token != NULL)
        { 
            array[j] = atoi(token);
            printf("Token %s",token);
            token = strtok(NULL," "); 
            j++;
        }
        
        int total = calculator(array[0],array[1],operator);
        sprintf(serverRepond,"%d %s %d = %d", array[0], operator, array[1], total);
        send(connfd,serverRepond,strlen(serverRepond),0);
        // Im done, spend 4 hour just to fix the bug, which make token can't free from memory, I'll love this
        // maybe i'll finish this thing later, but now the main function is fine 
        printf("[Server] message sent: %s\n",serverRepond);
        memset(buff,0,strlen(buff));
        memset(serverRepond,0,strlen(serverRepond));
        memset(array,0,sizeof(array));
        total = 0;
        close(connfd);
    }
}