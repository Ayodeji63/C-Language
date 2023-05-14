#include <stdio.h>
#include <math.h>

struct Student
{
    char firstName[50];
    char lastName[50];
    char department[50];
    float grades[10];
    float gpa[10];
    float cgpa[2];
};

void registerStudent(struct Student *student);
void printAllStudent(int numStudents, struct Student totalStudent[numStudents]);
void computeGPA(struct Student *student, int numSemester);
void classifyGrade(struct Student *student, int semester);
void checkProbation(struct Student *student, int year);
void computeCGPA(int firstSemester, int secondSemester, struct Student *student);

int main()
{
    int numStudents;
    int numSemester;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    printf("Enter the number of semster: ");
    scanf("%d", &numSemester);

    struct Student students[numStudents];

    for (int i = 1; i <= numSemester; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
        {
            int year;
            if (i == 1)
                printf("\nYear 1 \n");
            if (i == 3)
                printf("\nYear 2 \n");
            if (i == 5)
                printf("\nYear 3 \n");
            if (i == 7)
                printf("\nYear 4 \n");
            if (i == 9)
                printf("\nYear 5 \n");
        }

        printf("\nSemester %d:\n", i);
        for (int j = 0; j < numStudents; j++)
        {
            printf("\nStudent %d:\n", j + 1);
            registerStudent(&students[j]);
            computeGPA(&students[j], i);
            classifyGrade(&students[j], i);
            if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10)
            {
                printf("\n A year gone, CGPA below for %s", students[j].firstName);
                computeCGPA(i - 1, i, &students[j]);
                checkProbation(&students[j], (i / 2) - 1);
            }
        }
    }

    printAllStudent(numStudents, students);
}

void registerStudent(struct Student *student)
{
    printf("\nEnter student First Name: ");
    scanf("%s", student->firstName);
    printf("\nEnter student Last Name: ");
    scanf("%s", student->lastName);
    printf("Enter department: ");
    scanf("%s", student->department);
}

void printAllStudent(int numStudents, struct Student totalStudent[numStudents])
{
    for (int i = 0; i < numStudents; i++)
    {
        printf("\nStudent : %d\n", i + 1);
        printf("Name: %s %s \n", totalStudent[i].firstName, totalStudent[i].lastName);
        printf("Department: %s\n", totalStudent[i].department);

        for (int j = 0; j < sizeof(totalStudent[i].cgpa) / sizeof(totalStudent[i].cgpa[0]); j++)

        {
            printf("Year %d CGPA: %f\n", j + 1, totalStudent[i].cgpa[j]);
        }
    }
}

void computeGPA(struct Student *student, int semester)
{
    float totalCredits = 0.0;
    float weightedSum = 0.0;
    float points = 0.0;

    for (int i = 0; i < 2; i++)
    {
        printf("Enter Score for Course %d \n: ", i + 1);
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

        totalCredits += 5.0;         // Assuming each semester carries 5 credits
        weightedSum += points * 5.0; // Assuming each semester carries 5 credits
    }

    student->gpa[semester] = weightedSum / totalCredits;

    printf("Total GPA for semester %d \n: %lf", semester, student->gpa[semester]);
};

void classifyGrade(struct Student *student, int semester)
{
    if (student->gpa[semester] >= 4.5)
    {
        printf("\n %s has First Class in %d semester \n", student->firstName, semester);
    }
    else if (student->gpa[semester] >= 3.5)
    {
        printf("\n %s has Second Class Upper in %d semester\n", student->firstName, semester);
    }
    else if (student->gpa[semester] >= 2.5)
    {
        printf("\n %s has Second Class Lower in %d semester\n", student->firstName, semester);
    }
    else if (student->gpa[semester] >= 1.0)
    {
        printf("\n %s has Third Class in %d semester\n", student->firstName, semester);
    }
    else
    {
        printf("\n %s has Pass in %d semester\n", student->firstName, semester);
    }
}

void checkProbation(struct Student *student, int year)
{
    if (student->cgpa[year] < 1.0)
    {
        printf("Probation: CGPA < 1.0\n");
        // Additional code here for appropriate sanctions
        if (year == 2 && student->cgpa[1] < 1.0 && student->cgpa[2] < 1.0)
        {
            printf("Probation is inevitable");
        }
    }
}

void computeCGPA(int firstSemester, int secondSemester, struct Student *student)
{
    float CGPA = (student->gpa[firstSemester] + student->gpa[secondSemester]) / 2;
    student->cgpa[secondSemester / 2 - 1] = CGPA;
    printf("\n%s Session %d result %f \n", student->firstName, secondSemester / 2, student->cgpa[secondSemester / 2 - 1]);
}
