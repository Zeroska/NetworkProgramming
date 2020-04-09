#include "stdio.h"

void questionOne()
{
    printf("Computer Networking\nHoaSen University\n");
}

void questionTwo(int firstNumber, int secondNumber)
{
    if (firstNumber > secondNumber)
    {
        printf("%d\n", firstNumber);
    }
    printf("%d\n", secondNumber);
}

void questionThree(int firstNumber, int secondNumber, int thirdNumber)
{
    if (firstNumber > secondNumber)
    {
        if (firstNumber > thirdNumber)
        {
            printf("%d is the greatest among three \n",firstNumber);
        }
        else
        {
            printf("%d is the greatest among three \n",thirdNumber);
        }
    }
    else if (secondNumber > thirdNumber)
        printf("%d is the greatest among three \n",secondNumber);
    else
        printf("%d is the greatest among three \n",thirdNumber);
}

int questionFour(int n)
{
    int sum = 0;
    if (n < 50)
    {
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
    }
    else
    {
        sum = (n * (n + 1)) / 2;
    }
    return sum;
}

int questionFive(int n)
{
    int sum = 0;
    int i = 1;
    if (n < 50)
    {
        while (n <= 50)
        {
            sum += i;
            i++;
        }
    }
    else
    {
        sum = (n * (n + 1)) / 2; // this is the proven fomula and Im okay with it
    }
}

// ax + b = 0
void questionSix(float a, float b)
{
    if (a == 0)
    {
        if (b == 0)
        {
            printf("True with all x\n");
        }
        else
        {
            printf("No result for x)\n");
        }
    }
    else
    {
        printf("Result: x = %.2f\n", -b / a);
    }
}

void questionSeven(float length, float width, int measurement)
{
    float perimeter;
    float area;

    // translate all this into meter
    switch (measurement)
    {
    case 0:
        length /= 1000.0;
        width /= 1000.0;
    case 1:
        length /= 100.0;
        width /= 100.0;
        break;
    case 2:
        length /= 10.0;
        width /= 10.0;
        break;
    case 3:
        length *= 1000.0;
        width *= 1000.0;
        break;
    default:
        break;
    }
    perimeter = (width + length) * 2.0;
    area = width * length;
    printf("the perimeter %.2f \n the area %.2f", perimeter, area);
}
//HOW TO COMPILE THIS:
// Go to your bash termimal, make sure you have gcc or clang installed
// and go to directory that you save your source code
// type this base on your compiler
// if gcc: gcc -o <yourOutputName> -g -Wall <yourSourceCode>
// if clang: clang -o <yourOutputName> -g -Wall <yourSourceCode>

int main(void)
{
    int metric;
    int a, b; //for all the question
    printf("Just enter a and b and the rest is history\n");
    questionOne();
    questionTwo(23, 3);

    questionThree(1,2,3);
    questionFour(12);

    questionFive(100);
    questionSix(12.0, 6.5);
    // for laziness
    printf("0 is for mm\n1 is for cm\n 2 is for dm\n 3 is for km\n");
    scanf("%d", &metric);
    questionSeven(32.0, 12.0, metric);
}
