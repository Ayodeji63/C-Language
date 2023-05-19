#include <stdio.h>

void ReverseArray(int arr[], int size);
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);
void printArray(int arr[], int size);
int main()
{
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size], reverseArray[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    // Copying array to reverseArray
    for (i = 0; i < size; i++)
    {
        reverseArray[i] = array[i];
    }

    printf("\nOriginal Array: ");
    printArray(array, size);

    printf("Reversed Array: ");
    ReverseArray(reverseArray, size);
    printArray(reverseArray, size);

    printf("Array in Ascending Order: ");
    sortAscending(array, size);
    printArray(array, size);

    printf("Array in Descending Order: ");
    sortDescending(array, size);
    printArray(array, size);

    return 0;
}

void ReverseArray(int arr[], int size)
{
    int i, j, temp;
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void sortAscending(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
