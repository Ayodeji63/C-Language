#include <stdio.h>
#include <string.h>

int main()
{
    // for (int i = 10; i >= 0; i--)
    // {
    //     printf("%d \n", i);

    // }

    char s1[100] = "The rain semester exams is here";
    char s2[100] = "I have started mine";
    char s3[100] = "I will finish next week";
    int cmp = strcmp(s1, s2);
    int x = strlen(s1);
    char s5[100];
    char s6[100];
    strcpy(s5, s3);
    strcpy(s6, s1);
    strcat(s1, s2);
    printf("strcmp(s1, s2): %d\n", cmp);
    printf("strlen(s1): %d\n", x);
    printf("strcpy(s5, s3): %s\n", s5);
    printf("strcpy(s6, s2): %s\n", s1);
    printf(" strcat(s1, s2): %s\n", s1);
}