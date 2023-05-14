#include <stdio.h>

struct student
{
    int roll_number;
    char name[50];
    int age;
    float grade;
};

int main()
{
    struct student Students[5];

    printf("Enter Biodata\n");

    for (i = 0; i < 5; i++)
    {
        printf("student %d\n", i + 1);
        printf("Enter roll number: \n");
        scanf("%d", &Students[i].roll_number);
        printf("Enter name: \n");
        scanf("%s", Students[i].name);
        printf("Enter age: \n");
        scanf("%d", &Students[i].age);
        printf("Enter grade: \n");
        scanf("%f", &Students[i].grade);
        printf("\n");
    }
    for (int i = 0; i < 8; i++)
    {
        printf("Enterfor (int i = 0; i < 8; i++) grade for semester %d: ", i + 1);
        scanf("%f", &(student->grades[i]));

        totalCredits += 5.0; // Assuming each semester carries 5 credits

        // Convert grade to points
        float points;
        if (student->grades[i] >= 70)
        {
            points = 5.0;
        }
        else if (student->grades[i] >= 60)
        {
            points = 4.0;
        }
        else if (student->grades[i] >= 50)
        {
            points = 3.0;
        }
        else if (student->grades[i] >= 45)
        {
            points = 2.0;
        }
        else if (student->grades[i] >= 40)
        {
            points = 1.0;
        }
        else
        {
            points = 0.0;
        }

        weightedSum += points * 5.0; // Assuming each semester carries 5 credits
    }

    printf("Biodata of %d Students:\n", 5);

    for (i = 0; i < 5; i++)
    {
        printf("Roll Number: %d\n", Students[i].roll_number);
        printf("Name: %s\n", Students[i].name);
        printf("Age: %d\n", Students[i].age);
        printf("Grade: %lf\n", Students[i].grade);
    }

    return 0;
}
