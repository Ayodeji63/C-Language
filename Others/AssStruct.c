
#include <stdio.h>
#define MAX_STUDENTS 100

// Structure to store student attendance
struct Student
{
    int roll_number;
    char name[50];
    int attendance_status;
};

int main()
{
    struct Student attendance[MAX_STUDENTS]; // Array of structures
    int num_students, i;

    printf("Enter the number of students in the class: ");
    scanf("%d", &num_students);

    // Accept attendance details from the user
    printf("Enter attendance details for %d students:\n", num_students);
    for (i = 0; i < num_students; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &attendance[i].roll_number);
        printf("Enter Name: ");
        scanf("%s", attendance[i].name);
        printf("Enter Attendance Status (1 for Present, 0 for Absent): ");
        scanf("%d", &attendance[i].attendance_status);
        printf("\n");
    }

    // Display attendance
    printf("Attendance for %d students:\n", num_students);
    printf("%-15s %-15s %-10s\n", "Roll Number", "Name", "Status");
    for (i = 0; i < num_students; i++)
    {
        printf("%-15d %-15s %-10s\n", attendance[i].roll_number, attendance[i].name, attendance[i].attendance_status == 1 ? "Present" : "Absent");
    }

    return 0;
}