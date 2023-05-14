#include <stdio.h>

int main()
{
    // Create an integer variable that will store the number we get from the user
    int myNum;
    char firstName[30];

    // Ask the user to type a number
    printf("Type a number and press enter: \n");
    // Get and save the number the user types
    scanf("%d", &myNum);
    printf("Enter your first name: \n");
    scanf("%s", firstName);

    // Print the number the user typed
    printf("Your number is: %d \n", myNum);
    printf("Hello %s. \n", firstName);

    return 0;
}
