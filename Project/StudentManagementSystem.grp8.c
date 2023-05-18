#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100

typedef struct
{
    char name[50];
    int age;
    char program[20];
} Student;

typedef struct
{
    Student students[MAX_STUDENTS];
    int count;
} PostGraduateDatabase;

typedef struct
{
    Student students[MAX_STUDENTS];
    int count;
} UndergraduateDatabase;
typedef struct
{
    Student students[MAX_STUDENTS];
    int count;
} partTimeDatabase;

PostGraduateDatabase postDatabase;
UndergraduateDatabase underDatabase;
partTimeDatabase partDatabase;

// Function prototypes
void addStudent();
void printStudents();
void printStudentCount();
void deleteStudent();

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
        printf("2. Print Total Number Of Student In Each Category\n");
        printf("3. Delete Student\n");
        printf("4. Print Students\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            addStudent();
            break;
        case 2:
            printStudentCount();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            printStudents();
            break;
        default:
            break;
        }
    } while (choice != 6);
}

void addStudent()
{
    int count = postDatabase.count + underDatabase.count + partDatabase.count;
    if (count < MAX_STUDENTS)
    {
        int choice, index, age;
        char name[50], program[20];
        printf("\n======Add Student======:\n");
        printf("\nEnter student name: ");
        scanf(" %[^\n]", name);
        printf("Enter student age: ");
        scanf("%d", &age);
        printf("Enter student program (Undergraduate, Postgraduate, PartTime): ");
        scanf(" %[^\n]", program);

        Student newStudent;
        strcpy(newStudent.name, name);
        newStudent.age = age;
        strcpy(newStudent.program, program);
        if (strcmp(program, "Undergraduate") == 0)
        {
            underDatabase.students[underDatabase.count++] = newStudent;

            printf("Student added to undergraduate database successfully.\n");
        }
        if (strcmp(program, "Postgraduate") == 0)
        {
            postDatabase.students[postDatabase.count++] = newStudent;

            printf("Student added to postgraduate database successfully.\n");
        }
        if (strcmp(program, "PartTime") == 0)
        {
            partDatabase.students[partDatabase.count++] = newStudent;

            printf("Student added to part-time database successfully.\n");
        }
    }
    else
    {
        printf("Error: Maximum student capacity reached. \n");
    }
}

void printStudentCount()
{
    printf("======Total students======\n");
    printf("Undergraduate: %d\n", underDatabase.count);
    printf("Postgraduate: %d\n", postDatabase.count);
    printf("PartTime: %d\n", partDatabase.count);
}

void deleteStudent()
{
    char program[20], name[50];

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Student Program (Undergraduate, Postgraduate, PartTime): ");
    scanf(" %[^\n]", program);

    bool studentDeleted = false;

    if (strcmp(program, "Undergraduate") == 0)
    {
        for (int i = 0; i < underDatabase.count; i++)
        {
            if (strcmp(underDatabase.students[i].name, name) == 0)
            {
                // Shift the subsequent elements to the left
                for (int j = i; j < underDatabase.count - 1; j++)
                {
                    underDatabase.students[j] = underDatabase.students[j + 1];
                }
                underDatabase.count--;
                printf("Student deleted from the undergraduate database successfully.\n");
                studentDeleted = true;
                break;
            }
        }
    }
    else if (strcmp(program, "Postgraduate") == 0)
    {
        for (int i = 0; i < postDatabase.count; i++)
        {
            if (strcmp(postDatabase.students[i].name, name) == 0)
            {
                // Shift the subsequent elements to the left
                for (int j = i; j < postDatabase.count - 1; j++)
                {
                    postDatabase.students[j] = postDatabase.students[j + 1];
                }
                postDatabase.count--;
                printf("Student deleted from the postgraduate database successfully.\n");
                studentDeleted = true;
                break;
            }
        }
    }
    else if (strcmp(program, "PartTime") == 0)
    {
        for (int i = 0; i < partDatabase.count; i++)
        {
            if (strcmp(partDatabase.students[i].name, name) == 0)
            {
                // Shift the subsequent elements to the left
                for (int j = i; j < partDatabase.count - 1; j++)
                {
                    partDatabase.students[j] = partDatabase.students[j + 1];
                }
                partDatabase.count--;
                printf("Student deleted from the part-time database successfully.\n");
                studentDeleted = true;
                break;
            }
        }
    }

    if (!studentDeleted)
    {
        printf("Student not found in the specified program.\n");
    }
}

void printStudents()
{
    int count = postDatabase.count + underDatabase.count + partDatabase.count;
    if (count == 0)
    {
        printf("No students found.\n");
    }
    else
    {
        if (underDatabase.count > 0)
        {
            printf("\n======All Undergraduate Students======:\n");
            printf("%-25s %-20s %-10s\n", "Name", "Age", "Program");
            for (int i = 0; i < underDatabase.count; i++)
            {
                printf("%-25s %-20d %-10s", underDatabase.students[i].name, underDatabase.students[i].age, underDatabase.students[i].program);

                printf("\n");
            }
        }

        if (postDatabase.count > 0)
        {
            printf("\n======All Postgraduate Students======:\n");
            printf("%-25s %-20s %-10s\n", "Name", "Age", "Program");
            for (int i = 0; i < underDatabase.count; i++)
            {
                printf("%-25s %-20d %-10s", postDatabase.students[i].name, postDatabase.students[i].age, postDatabase.students[i].program);

                printf("\n");
            }
        }

        if (partDatabase.count > 0)
        {
            printf("\n======All Part-Time Students======:\n");
            printf("%-25s %-20s %-10s\n", "Name", "Age", "Program");
            for (int i = 0; i < partDatabase.count; i++)
            {
                printf("%-25s %-20d %-10s", partDatabase.students[i].name, partDatabase.students[i].age, partDatabase.students[i].program);
                printf("\n");
            }
        }
    }
}