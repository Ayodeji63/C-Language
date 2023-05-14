#include <stdio.h>

int main()
{
    char name[30];
    int matricNum;

    printf("What is your first name\n");
    scanf("%s", name);
    printf("What is your Matric number \n");
    scanf("%d", &matricNum);

    printf("Your name is %s \n", name);
    printf("Your matric number is %d \n", matricNum);
    return 0;
}