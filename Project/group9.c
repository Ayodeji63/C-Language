#include <stdio.h>
#include <math.h>

struct Student
{
    char firstName[50];
    char lastName[50];
    char department[50];
    float grades[10];
    float semesterGPA[4];
    float cumulativeGPA[2];
};

// Function declarations
void registerStudentInfo(struct Student *student);
void printAllStudents(int numStudents, struct Student totalStudents[numStudents]);
void computeSemesterGPA(struct Student *student, int semester);
void classifyGrade(struct Student *student, int semester);
void checkProbationStatus(struct Student *student, int year);
void computeCumulativeGPA(int firstSemester, int secondSemester, struct Student *student);

int main()
{
    int numStudents;
    int numSemesters;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    printf("Enter the number of semesters: ");
    scanf("%d", &numSemesters);

    struct Student students[numStudents];

    for (int i = 1; i <= numSemesters; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
        {
            int year;
            if (i == 1)
                printf("\nYear 1\n");
            if (i == 3)
                printf("\nYear 2\n");
            if (i == 5)
                printf("\nYear 3\n");
            if (i == 7)
                printf("\nYear 4\n");
            if (i == 9)
                printf("\nYear 5\n");
        }

        printf("\nSemester %d:\n", i);
        for (int j = 0; j < numStudents; j++)
        {
            printf("\nStudent %d:\n", j + 1);
            registerStudentInfo(&students[j]);
            computeSemesterGPA(&students[j], i);
            classifyGrade(&students[j], i);
            if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10)
            {
                printf("\nA year has passed. Calculating CGPA for %s", students[j].firstName);
                computeCumulativeGPA(i - 1, i, &students[j]);
                checkProbationStatus(&students[j], (i / 2) - 1);
            }
        }
    }

    printAllStudents(numStudents, students);
}

void registerStudentInfo(struct Student *student)
{
    printf("\nEnter student's First Name: ");
    scanf("%s", student->firstName);
    printf("Enter student's Last Name: ");
    scanf("%s", student->lastName);
    printf("Enter department: ");
    scanf("%s", student->department);
}

void printAllStudents(int numStudents, struct Student totalStudents[numStudents])
{
    for (int i = 0; i < numStudents; i++)
    {
        printf("\nStudent: %d\n", i + 1);
        printf("Name: %s %s\n", totalStudents[i].firstName, totalStudents[i].lastName);
        printf("Department: %s\n", totalStudents[i].department);

        for (int j = 0; j < sizeof(totalStudents[i].cumulativeGPA) / sizeof(totalStudents[i].cumulativeGPA[0]); j++)
        {
            printf("Year %d CGPA: %f\n", j + 1, totalStudents[i].cumulativeGPA[j]);
        }
    }
}

void computeSemesterGPA(struct Student *student, int semester)
{
    float totalCredits = 0.0;
    float weightedSum = 0.0;
    float points = 0.0;

    for (int i = 0; i < 2; i++)
    {
        printf("Enter score for Course %d: ", i + 1);
        scanf("%f", &(student->grades[i]));

        // Convert grade to points
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

        totalCredits += 5.0;         // Assuming each course carries 5 credits
        weightedSum += points * 5.0; // Assuming each course carries 5 credits
    }

    student->semesterGPA[semester] = weightedSum / totalCredits;

    printf("Total GPA for semester %d: %lf", semester, student->semesterGPA[semester]);
};

void classifyGrade(struct Student *student, int semester)
{
    if (student->semesterGPA[semester] >= 4.5)
    {
        printf("\n%s has First Class in semester %d\n", student->firstName, semester);
    }
    else if (student->semesterGPA[semester] >= 3.5)
    {
        printf("\n%s has Second Class Upper in semester %d\n", student->firstName, semester);
    }
    else if (student->semesterGPA[semester] >= 2.5)
    {
        printf("\n%s has Second Class Lower in semester %d\n", student->firstName, semester);
    }
    else if (student->semesterGPA[semester] >= 1.0)
    {
        printf("\n%s has Third Class in semester %d\n", student->firstName, semester);
    }
    else
    {
        printf("\n%s has Pass in semester %d\n", student->firstName, semester);
    }
}

void checkProbationStatus(struct Student *student, int year)
{
    if (student->cumulativeGPA[year] < 1.0)
    {
        printf("Probation: CGPA < 1.0\n");
        // Additional code here for appropriate actions
        if (year == 2 && student->cumulativeGPA[1] < 1.0 && student->cumulativeGPA[2] < 1.0)
        {
            printf("Probation is inevitable");
        }
    }
}

void computeCumulativeGPA(int firstSemester, int secondSemester, struct Student *student)
{
    float CGPA = (student->semesterGPA[firstSemester] + student->semesterGPA[secondSemester]) / 2;
    student->cumulativeGPA[secondSemester / 2 - 1] = CGPA;
    printf("\n%s Session %d result: %f\n", student->firstName, secondSemester / 2, student->cumulativeGPA[secondSemester / 2 - 1]);
}
