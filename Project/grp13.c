#include <stdio.h>
#include <string.h>

#define MAX_NAMES 10
#define MAX_NAME_LENGTH 50

void searchName(char names[][MAX_NAME_LENGTH], int count);
void sortNames(char names[][MAX_NAME_LENGTH], int count, int order);
void printNames(char names[][MAX_NAME_LENGTH], int count);

int main()
{
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int count = 0;
    int choice;

    printf("Enter the names of students (up to %d names).\n", MAX_NAMES);

    // Read the names from the user
    while (count < MAX_NAMES)
    {
        printf("Enter name %d (or 'q' to stop): ", count + 1);
        if (scanf(" %[^\n]", names[count]) != 1)
            break;
        count++;
    }

    // Prompt the user for search and sort options
    printf("\n");
    printf("1. Search for a name\n");
    printf("2. Sort the names in ascending order\n");
    printf("3. Sort the names in descending order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        searchName(names, count);
        break;
    case 2:
        sortNames(names, count, 1); // 1 represents ascending order
        printNames(names, count);
        break;
    case 3:
        sortNames(names, count, 0); // 0 represents descending order
        printNames(names, count);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}

void searchName(char names[][MAX_NAME_LENGTH], int count)
{
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(names[i], searchName) == 0)
        {
            printf("Name found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Name not found\n");
}

void sortNames(char names[][MAX_NAME_LENGTH], int count, int order)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            int compare = strcmp(names[j], names[j + 1]);

            if ((compare > 0 && order == 1) || (compare < 0 && order == 0))
            {
                char temp[MAX_NAME_LENGTH];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

void printNames(char names[][MAX_NAME_LENGTH], int count)
{
    printf("\nSorted names:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, names[i]);
    }
}
