#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000
#define UPPER 99
#define LOWER 1
struct Student{
    int number;
    char name[MAX];
    int yob;
    char class[MAX];
};

// 1.Write a program to put the inputted information (from keyboard) to a file whose name is inputted by users

// 2.Write a program to open a file and print out data of that file, the file name is inputted by users

// 3.Write a program to create an n*m matrix of integers (from 1-99, randomly). Print out the matrix, write the matrix to “matrix.txt”.

// 4.Write a program to read “matrix.txt”, put the values to an array and find the total value of each row. 

// 5.Write a program to remove all redundant spaces in a file.

// 6.Write a program to input the information (student’s number, name, year of birth, class) of students (using struct). Write the information to students.txt

// 7.Read students.txt, put the information to an array of struct student. Find the youngest student.





//[*] Exercise 1
void write(char fileName[], char userInput[]){
    printf("Your file name please: ");
    gets(fileName);
    printf("Input:\n");
    fgets(userInput,MAX,stdin);
    FILE *f = fopen(fileName,"w");
    if (f == NULL){
        printf("Something went wrong!!\n");
    }else{
        fputs(userInput,f);
    }
    fclose(f);
}
//I could combine ex1 and ex2 into one function 

//[*] Exercise 2
//just like cat in UNIX 
void cat(FILE* f) {
  int c;
  while(EOF != (c = getc(f))) {
    if (EOF == putchar(c)) {
      perror("read");
      return;
    }
  }
  if (ferror(f)) {
    perror("read");
    return;
  }
}

void read(char fileName[]){
    printf("Your file name please: ");
    gets(fileName);
    FILE *f = fopen(fileName,"r");
    if (f == NULL){
        printf("Something went wrong!!\n");
    }else{
        cat(f);
    }
    fclose(f);
}


//[*] Exercise 3
void createMatrix(int n, int m){
    FILE *f = fopen("matrix.txt","w");
    if (f == NULL){
        printf("Something is not right!\n");
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //this will gen a random number in range of 1 -99
                //because rand() is gen a random number in 0 to RAND_MAX (atleast 2^15)
                fprintf(f,"%d ",(rand() % (UPPER-LOWER)+1) + LOWER);
            }
            fprintf(f,"\n");
        }
    }
    fclose(f);
   
}

//[*] Exercise 4
void sumOfEachLineMatrix(int n,int m){ //I don't wnat to count the n and m so I do this much easier 
    FILE *f = fopen("matrix.txt","r");
    int size = m*n;
    int array[size];
    
    if(f == NULL){
        printf("WRONNGGG WROONGGGG\n");
    }
    else{
        for(int i  = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                fscanf(f,"%d ",&array[i]); 
            }
            fscanf(f,"\n");
        }
        int flag = 0;
        int row = 1; 
        int total = 0;
        for(int z = 1; z <= size;z++){
            printf("%d\n",array[z]);
            if (z % m == 0){ //m is number of element in on row (we could say that is column)
                flag = 1;
                printf("Total of row %d: %d\n", row, total+= array[z]);
                row++;
            }
            if(flag == 0)
            {
                total += array[z];
            }
            else{
                total = 0;
            }
        }

    }
}

//[*] Exercise 6
void inputStudentInformationToFile(struct Student student){
    FILE *f = fopen("student.txt","a");//append at the end of the file
    if(f == NULL){
        printf("File is stupid ....\n");
    }else{
        fprintf(f,"Name: %s\n",student.name);
        fprintf(f,"Number: %d\n",student.number);
        fprintf(f,"Yob: %d\n",student.yob);
        fprintf(f,"class: %s\n",student.class);
        fprintf(f,"\n");
    }
}

//[*] Exercise 7
void findTheYougestStudent(){
    FILE *f = fopen("student.txt","r");
    if (f == NULL){
        printf("Opss!");
    }else{
        while(1){
            
        }
    }
}


//Please uncomment before run this 
int main(){
    char fileName[MAX];
    char userInput[MAX];
    int n ,m;
    struct Student student;
    // printf("Enter Student Name:");
    // scanf("%s",student.name);
    // printf("Enter Student Number:");
    // scanf("%d",&student.number);
    // printf("Enter Student Yob:");
    // scanf("%d",&student.yob);
    // printf("Enter Student class:");
    // scanf("%s",student.class);
    //write(fileName,userInput);
    //read(fileName);
    printf("Enter n and m\n");
    scanf("%d",&n);
    scanf("%d",&m);
    // createMatrix(n,m);
    // inputStudentInformationToFile(student);
    sumOfEachLineMatrix(n,m);
}