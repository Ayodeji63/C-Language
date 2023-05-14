#include <stdio.h>
int numval;
int main()
{
    printf("How many values \n");
    scanf("%d", &numval);
    int loopcounter;
    int value;
    int result = 0;
    for (loopcounter = 0; loopcounter < numval; loopcounter++)
    {
        result = result + loopcounter;
    }
    printf("Result= %d \n", result);
    return result;
}
