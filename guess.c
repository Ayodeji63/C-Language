#include <stdio.h>

int main()
{
    int hidnum = 5;
    int guessnum;
    do
    {
        printf("Guess the hidden number: \n");
        scanf("%d", &guessnum);
    } while (hidnum != guessnum);

    printf("You guess the right number %d \n", guessnum);
    return 0;
}