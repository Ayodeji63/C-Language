#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} StudentDatabase;

// Function prototypes
void initializeDatabase(StudentDatabase *db);
void addStudent(StudentDatabase *db, const char *name, int age, const char *program);
void deleteStudent(StudentDatabase *db, int index);
void sortStudents(StudentDatabase *db);
void printStudents(StudentDatabase *db);
void printStudentCount(StudentDatabase *db);

int main()
{
    StudentDatabase database;
    initializeDatabase(&database);

    // Adding sample students
    addStudent(&database, "John Doe", 20, "Undergraduate");
    addStudent(&database, "Jane Smith", 25, "Postgraduate");
    addStudent(&database, "David Johnson", 30, "Part-time");
    addStudent(&database, "Emily Davis", 22, "Undergraduate");
    addStudent(&database, "Michael Wilson", 28, "Postgraduate");

    printf("Student Registration System\n");

    int choice, index;
    char name[50], program[20];
    int age;

    do
    {
        printf("\n1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Sort students\n");
        printf("4. Print students\n");
        printf("5. Print student count\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter student name: ");
            scanf(" %[^\n]", name);
            printf("Enter student age: ");
            scanf("%d", &age);
            printf("Enter student program: ");
            scanf(" %[^\n]", program);
            addStudent(&database, name, age, program);
            printf("Student added successfully.\n");
            break;
        case 2:
            printf("Enter index of student to delete: ");
            scanf("%d", &index);
            deleteStudent(&database, index);
            break;
        case 3:
            sortStudents(&database);
            printf("Students sorted successfully.\n");
            break;
        case 4:
            printf("Students:\n");
            printStudents(&database);
            break;
        case 5:
            printStudentCount(&database);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeDatabase(StudentDatabase *db)
{
    db->count = 0;
}

void addStudent(StudentDatabase *db, const char *name, int age, const char *program)
{
    if (db->count < MAX_STUDENTS)
    {
        Student newStudent;
        strcpy(newStudent.name, name);
        newStudent.age = age;
        strcpy(newStudent.program, program);

        db->students[db->count++] = newStudent;
    }
    else
    {
        printf("Error: Maximum student capacity reached.\n");
    }
}

void deleteStudent(StudentDatabase *db, int index)
{
    if (index >= 0 && index < db->count)
    {
        for (int i = index; i < db->count - 1; i++)
        {
            db->students[i] = db->students[i + 1];
        }
        db->count--;
        printf("Student deleted successfully.\n");
    }
    else
    {
        printf("Error: Invalid student index.\n");
    }
}

void sortStudents(StudentDatabase *db)
{
    for (int i = 0; i < db->count - 1; i++)
    {
        for (int j = 0; j < db->count - i - 1; j++)
        {
            if (strcmp(db->students[j].name, db->students[j + 1].name) > 0)
            {
                Student temp = db->students[j];
                db->students[j] = db->students[j + 1];
                db->students[j + 1] = temp;
            }
        }
    }
}

void printStudents(StudentDatabase *db)
{
    if (db->count == 0)
    {
        printf("No students found.\n");
    }
    else
    {
        for (int i = 0; i < db->count; i++)
        {
            printf("Name: %s\n", db->students[i].name);
            printf("Age: %d\n", db->students[i].age);
            printf("Program: %s\n", db->students[i].program);
            printf("\n");
        }
    }
}

void printStudentCount(StudentDatabase *db)
{
    printf("Total students:\n");
    printf("Undergraduate: %d\n", db->count);
    printf("Postgraduate: %d\n", db->count);
    printf("Part-time: %d\n", db->count);
}
