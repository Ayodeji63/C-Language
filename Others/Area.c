#include <stdio.h>

int main()
{
    int b;
    int h;
    printf("=======Calculate Area of a Triangle=======\n");
    printf("Input the base of the Triangle: ");
    scanf("%d", &b);
    printf("The base of the triangle is %d \n", b);
    printf("Input the height of the triangle: ");
    scanf("%d", &h);
    printf("The height of the triangle is %d \n \n", h);

    printf("=======The Area of the triangle is=========\n \n");

    float area = 0.5 * b * h;

    printf("Area of triangle is == %f \n", area);
}