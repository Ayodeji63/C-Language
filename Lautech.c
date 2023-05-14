#include <stdio.h>

typedef struct
{
    char name[50];
    int department;
    float grades[8]; // Assuming 8 semesters
    float cgpa;
} Student;

void registerStudent(Student *student)
{
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter department code (e.g., 1 for Computer Science): ");
    scanf("%d", &(student->department));
}

void computeCGPA(Student *student)
{
    float totalCredits = 0.0;
    float weightedSum = 0.0;

    for (int i = 0; i < 10; i++)
    {
        printf("Enter grade for semester %d \n: ", i + 1);
        scanf("%f", &(student->grades[i]));

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

        totalCredits += 5.0;         // Assuming each semester carries 5 credits
        weightedSum += points * 5.0; // Assuming each semester carries 5 credits

        // Clear input buffer
        while (getchar() != '\n')
            ;
    }

    student->cgpa = weightedSum / totalCredits;
}

void classifyGrade(Student *student)
{
    if (student->cgpa >= 4.5)
    {
        printf("First Class\n");
    }
    else if (student->cgpa >= 3.5)
    {
        printf("Second Class Upper\n");
    }
    else if (student->cgpa >= 2.5)
    {
        printf("Second Class Lower\n");
    }
    else if (student->cgpa >= 1.0)
    {
        printf("Third Class\n");
    }
    else
    {
        printf("Pass\n");
    }
}

void checkProbation(Student *student)
{
    if (student->cgpa < 1.0)
    {
        printf("Probation: CGPA < 1.0\n");
        // Additional code here for appropriate sanctions
    }
}

int main()
{
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student students[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        registerStudent(&students[i]);
        computeCGPA(&students[i]);

        printf("\nCGPA: %.2f\n", students[i].cgpa);
        classifyGrade(&students[i]);
        checkProbation(&students[i]);
    }

    return 0;
}
