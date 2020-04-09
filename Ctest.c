#include "stdio.h"


int* pasingAnArray(){
    static int something[10];
    for(int i  = 0 ; i < 10;i++)
    {
        something[i] = i;
    }
    return something;
}


int main(){
    //extern indicate that an indentifier is defined elsewhere
    int* khuong = pasingAnArray();
    for (int i = 0;i < 10;i++){
        printf("%d\n", *(khuong + i));
    }
}