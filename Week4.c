#include <stdio.h>
#define NEXT_CHARACTER 1 // plus one
#define MAX 32768

struct student{
    char name[MAX];
    int yob;
};
/*
1.Write a program to count the number of characters in a string without using strlen() function

2.Write a function to count the number of occurrences of a character in a string without using functions in string.h library

3.Write a program to combine 2 strings into another string without using functions in string.h library

4.Write a program to count the number of words in a string

5.Write a function to remove all spaces in a string

6.Write a function to remove all redundant spaces in a string

7.Write a program to reverse a string without using functions in string.h library

8.Write a program to input the information of 2 students: name, year of birth, class (using struct). Print out the information of the younger student
*/
int length(char string[]);
int countOccurrences(char string[], char letter);
int countWords(char string[]);
void removeAllSpace(char string[]);
void checkWhoYounger(struct student a, struct student b);
void reverseString(char string[]);

int main(void){
    //Okay okay not the best main function
    char khuong[] = "kkkkhuong", letter ='k';
    int len = length(khuong);
    printf("len of khuong is %d\n",len); //len without the \0 
    int b  = countWords(khuong);
    printf("%d",b);
    removeAllSpace(khuong);
    printf("\n%s",khuong);
    int a = countOccurrences(khuong,letter);
    printf("\n%d",a);
    reverseString(khuong);
    printf("\n%s",khuong);
    struct student someone1;
    struct student someone2;
    printf("Student 1: \n");
    scanf("%s",someone1.name);
    scanf("%d",&someone1.yob);
    printf("Student 2: \n");
    scanf("%s",someone2.name);
    scanf("%d",&someone2.yob);
    checkWhoYounger(someone1,someone2);

}

//[*] Question 1
int length(char string[]){
    int character = 0;
    int count = 0;
    while(string[character] != '\0' ){
        count ++;
        character++;
    }
    return count;
}

//[*] Question 2
int  countOccurrences(char string[], char letter){
    int character = 0;
    int occurences = 0;
    while(string[character] != '\0'){
        if (string[character] == letter){
            occurences++;
        }
        character++;
    }
    return occurences;
}

//[*] Question 3
// void concat(char dest[], char source[]){
//     int character = 0;
//     char temp[MAX];
//     while()
// }

//[*] Question 4
// khuong  = 1 word
int countWords(char string[]){
    //this thing do its job until you put space before the first word and then the hold thing start to collapse
    int character = 0;
    int count = 0;
    while(string[character] != '\0'){
        //this condition is horible(to read)
        if((string[character] == ' ' && string[character +NEXT_CHARACTER] != ' ')|| string[character] == '\n' || string[character] == '\t'){
            count++;
        }
        character++;
    }
    return count;
}

//[*] Question 5

void removeAllSpace(char string[]){
    int len = length(string);
    for(int i = 0; i < len; i++){
        if(string[i] == ' '){
            for(int j = i; j < len; j++){
                string[j] = string[j +1 ];
            }
            len--;
        }
    }
}

//[*] Question 6

//[*] Question 7
void reverseString(char string[]){
    int g,  numb;
    int tmpry = 0; //ayy this is the length I created
    for(numb=0; string[numb] != '\0'; numb++); //swaping
    for(g = 0; g <numb/2; g++)
    {
        tmpry = string[g];
        string[g]=string[numb - 1 - g];
        string[numb - 1 - g] = tmpry;
    }
}
//[*] Question 8

void checkWhoYounger(struct student a, struct student b){
    //Okay I gonna admit this thing not gonna work flawlessly (the case where both student is the same age will always return a is younger)
    if (a.yob > b.yob){
        printf("%s is younger",b.name);
    }else{
        printf("%s is younger",a.name);
    }
}




