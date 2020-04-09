#include <stdio.h>
#include <string.h>
int main()
{
     char first[30] = "string 1";
     char second[40] = "string 2: I’m using strncpy now";
     /* this function has copied first 10 chars of s2 into s1*/
     strncpy(first,second, 12);
     printf("String s1 is: %s", first);
     return 0;
}