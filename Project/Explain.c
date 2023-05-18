#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct
{
    char name[50];
    int age;
    char program[30];
} Student;

typedef struct
{
    // data type //variable
    Student students[MAX_STUDENTS];
    int count;
} UndergrduateDatabase;

typedef struct
{
    // data type //variable
    Student students[MAX_STUDENTS];
    int count;
} PostGraduateDatabase;

typedef struct
{
    // data type //variable
    Student students[MAX_STUDENTS];
    int count;
} PartTimeDatabase;

UndergrduateDatabase underDatabase;
PostGraduateDatabase postDatabase;
PartTimeDatabase partDatabase;

// Functions Decleration
void addStudent();

int main()
{
    postDatabase.count = 0;
    underDatabase.count = 0;
    partDatabase.count = 0;

    printf("Student Registration System\n");

    int choice;
    do
    {
        printf("\n1. Add Student\n");
        printf("Enter Your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        default:
            break;
        }
    } while (choice != 2);
}

// Initilaize the function

void addStudent()
{
    int count = postDatabase.count + underDatabase.count + partDatabase.count;

    if (count < MAX_STUDENTS)
    {
        int age;
        char name[30], program[30];
        printf("\n======Add Student======:\n");
        printf("\nEnter student name: ");
        scanf(" %[^\n]", name);
        printf("Enter student age: ");
        scanf("%d", &age);
        printf("Enter student program(Undergradute, Postgraduate, PartTime): ");
        scanf(" %[^\n]", program);

        Student newStudent;
        strcpy(newStudent.name, name);
        newStudent.age = age;
        strcpy(newStudent.program, program);
    }
}