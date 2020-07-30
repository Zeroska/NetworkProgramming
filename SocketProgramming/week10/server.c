#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define PORT 1337
#define STACK_MAXIMUM 9999

//Implement stack to the calculator, prefix notataion
//OPERATOR = 0, OPERAND = 1
#define OPERAND 10
#define OPERATOR 20
//Stack data struture.
typedef struct preFix{
    int top;
    int stackMax[STACK_MAXIMUM];
}Stack;

void init(Stack *stack){
    stack->top = -1;
}

void push(Stack *stack, int num){
    if(stack->top == STACK_MAXIMUM){
        perror("[!] YOU ALMOST SMASH THE STACK\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->stackMax[stack->top] = num; //top of the stack is equal to number added
}

//Pop one element out of the stack and then return its value
int pop(Stack *stack){
    int num = 0;
    num = stack->stackMax[stack->top];
    if (stack->top == -1){
        printf("[!] STACK UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    stack->top--;
    return num;
}

int top(Stack *stack){
    return stack->stackMax[0];
}

//do computation
void eval(Stack *stack, char operator, int number1, int number2){
    int result;
    switch(operator){
        case '+':
        {
            result = number1 + number2;
            break;
        }
        case '-':
        {
            result = number1 - number2;
            break;
        }
        case '*':
        {
            result = number1 * number2;
            break;
        }
        case '/':
        {
            result = number1 * number2;
            break; 
        }
        case '%':
        {
            result = number1 % number2;
            break;
        }
    }
    push(stack,result);
}

//just clasify all the operator and operand 
int gettype(char character){
    switch (character){
        case '+':
        case '-':
        case '/':
        case '*':
        case '%': 
            return OPERATOR;
        default:
            return OPERAND;
    }
}


char *calculate(char *string, char* result ){
        Stack stack;
		int num1,num2,item,l;
		init(&stack);
		l=strlen(string);

		for(int i=l-1;i>=0;i--)
		{   
            
			if(string[i]==' ' || string[i]=='\0') //just in case! for space nd \0
				continue;
			switch(gettype(string[i])) // process type
			{
				case OPERAND :
                {
					item=string[i] - '0'; // string to int conversion
					push(&stack,item);
                    break;
                }
				
				case OPERATOR :
                {
					num1=pop(&stack);
					num2=pop(&stack);
					eval(&stack,string[i],num1,num2);
                    break;
                }
			}
            printf("pre[i] = %s\n", &string[i]);
            printf("item: %d\n",item);
            printf("stack top: %d\n\n",stack.top);
		}
        printf("top %d\n",stack.top);
        snprintf(result, sizeof result,"%d",top(&stack));
        return result;
}


int main(void){
    int connfd;
    struct sockaddr_in servAddr, cliaddr;
    char userInput[BUFSIZE] = {0};
    char serverResponse[BUFSIZE] = {0};

    if((connfd = socket(AF_INET,SOCK_DGRAM,0)) < 0){
        perror("[!] Something in socket() is wrong\n");
        exit(EXIT_FAILURE);
    }
    //seting up socket()
    memset(&servAddr, 0, sizeof servAddr);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(connfd,(struct sockaddr*)&servAddr, sizeof servAddr) < 0){
        perror("[!] Something in bind() is wrong\n");
        exit(EXIT_FAILURE); //it just represent 1
    }
    //it tells me to use unsigned so yah
    uint len = sizeof cliaddr; 

    while(1){
        memset(userInput, 0, sizeof userInput);
        memset(serverResponse,0,sizeof serverResponse);
        recvfrom(connfd, userInput, BUFSIZE, 0, (struct sockaddr *) &cliaddr, &len);
        printf("Trying to calculate %s\n", userInput);
        calculate(userInput,serverResponse);
        sendto(connfd, serverResponse, BUFSIZE, 0, (struct sockaddr *) &cliaddr, len);
        printf("Send to client %s\n", serverResponse);
    }

    return 0;
}