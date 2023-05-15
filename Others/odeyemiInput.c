#include <stdio.h>

void odeyemuiInput(){};
int main()
{
    char name[50];
    // int
    // float
    // double
    printf("Enter your Name: ");
    scanf("%[^\n]", name);
    printf("Your name is %s\n", name);
}