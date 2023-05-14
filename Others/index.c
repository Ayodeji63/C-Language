#include <stdio.h>

int main()
{
    int myNumbers[] = {25, 50, 75, 100};
    myNumbers[0] = 33;
    // printf("%d \n", myNumbers[0] + myNumbers[3]);
    for (int i = 0; i < 4; i++)
    {
        // printf("%d\n", myNumbers[i]);
    }

    int matrix[2][3] = {{1, 4, 2}, {3, 6, 8}};
    // printf("%d \n", matrix[0][2]);

    // matrix[0][0] = 9;
    // printf("%d", matrix[0][0]);

    for (int i = 0; i < 2; i++)
    {
        // printf("%d \n", i);
        for (int j = 0; j < 3; j++)
        {
            // printf("%d \n", j);
            // printf("%d\n", matrix[i][j]);
        }
    }

    char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};

    char greetind2[] = "Hello world";

    // printf("%lu\n", sizeof(greetings));
    // printf("%lu\n", sizeof(greetind2));

    char txt[] = "We are the so-called \"Vikings\" from the north.";
    char text2[] = "It\'s alright.";
    char txt3[] = "The character \\ is called backlash.";
    // printf("%s \n", txt);
    // printf("%s \n", text2);
    // printf("%s \n", txt3);

    int myNum;
    printf("Type a number: \n");
    scanf("%d", &myNum);
    printf("Your number is: %d", myNum);
    return 0;
}