#include <stdio.h>



// 1. Write a program to input data into an array of integers and print out all elements in that array.

// 2. Write a function to print out the total value of all elements in an array.

// 3. Write a program to find an element with the biggest value in an n-element array (print out the position and the value of that element).

// 4. Write a program to find and swap the positions of the elements with the biggest and the smallest value in an n-element array.

// 5. Write a function to check whether an n-element array is in an ascending order.

// 6. Write a program to print out n square numbers in [a,b], in which n,a,b are inputted by users.

// 7. Write a program to print out all odd-position elements that are prime numbers in an n-element array.


//[Question 1]



void inputDataToArray(int yourArray[], int len)
{
    for(int i = 0; i < len;i++){
        printf("[*] Enter your [%d] data into array: ",i);
        scanf("%d",&yourArray[i]);
    }
    printf("[*] Elements in the array:\t");
    for(int j = 0; j < len;j++){
        printf("%d\t",yourArray[j]);
    }
    printf("\n");
}

void outputArrayData(int yourArray[], int len){
    printf("[*] Elements in the array:\t");
    for(int j = 0; j < len;j++){
        printf("%d\t",yourArray[j]);
    }
    printf("\n");
}
//[Question 2]
int sumOfAllElementInArray(int yourArray[], int len){
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += yourArray[i];
    }
    return sum;
}
//[Question 3]
void findBiggestValueInArray(int yourArray[], int len){
    int theBiggest = 0;
    int position = 0;
    for (int i = 0; i <len; ++i){
        if (yourArray[i] >= theBiggest){
            theBiggest = yourArray[i];
            //printf("%d\n",theBiggest);
            position = i;
        }
    }
    printf("[*] The biggest value %d and its position in the array [%d]\n",theBiggest,position);
}
void findSmallestValueInArray(int yourArray[], int len){
    int theSmallest = yourArray[0];
    int position = 0;
    for (int i  = 1; i < len;i ++){
        if (yourArray[i] < theSmallest){
            theSmallest = yourArray[i];
            position = i;
        }
    }
    printf("[*] The smallest value %d and its position in the array [%d]\n",theSmallest,position);
}
//[Question 4]

void swapSmallestWithTheBiggest(int yourArray[], int len){
    int smallest = yourArray[0];
    int biggest = 0;
    int posBig = 0, posSmall = 0;
    for(int i = 0; i < len; i++){
        if(yourArray[i] < smallest){
            smallest = yourArray[i];
            posBig = i;
        }
        if(yourArray[i] > biggest){
            biggest = yourArray[i];
            posSmall = i;
        }
    }

    int temp = yourArray[posBig];
    yourArray[posBig] = yourArray[posSmall];
    yourArray[posSmall] = temp;
    outputArrayData(yourArray,len);
  
}

//[Question 5]
void checkAscending(int yourArray[], int len){
    for(int i = 0; i < len; i++){
        for(int j = 1; j < len; j++){
            if(yourArray[i] <= yourArray[j])
            {
                continue;
            }
            else
            {
                printf("[*] Ascending: NO\n");
                break;
            }
        }
        break;
    }
    printf("[*] Ascending: YES\n");
}

//[Question 6]
//square number should range ...
// I don't even know    
void printOutSquareNumber(int n,int a,int b){
    for(int i = a; i < b;i++){
        if (n*n ){

        }
    }
}


//[Question 7]
int isPrime(int number){
    for (int i = 2; i <= number/2 ;i++){
        if(number % i == 0){
            return 0;
        }
    }
    return 1;
}
void printOddPositionPrimeNumber(int yourArray[], int len){
    for(int i = 0;i < len;i+=2){
        if(isPrime(yourArray[i])==1)
        {
            printf("[*] Prime number in odd position %d position [%d]\n",yourArray[i],i);
        }
        else{
            printf("[*] %d is not a prime number is odd position [%d]\n", yourArray[i],i);
        }
    }
}






int main(){
    int size = 0;
    int a,b,n;
    printf("Enter the size of the array you want: ");
    scanf("%d", &size);
    int array[size];
    fflush(stdin);
    
    inputDataToArray(array,size);
    int sum = sumOfAllElementInArray(array,size);
    printf("[*] Sum is: %d\n",sum);
    findBiggestValueInArray(array,size);
    findSmallestValueInArray(array,size);
    checkAscending(array,size);
    printOddPositionPrimeNumber(array,size);
    printf("-------AFTER SWAP-------\n");
    swapSmallestWithTheBiggest(array,size);
    printf("Please Input a, b and n\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&n);
}
