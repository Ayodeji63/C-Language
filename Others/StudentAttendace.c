#include <stdio.h>
#include <stdbool.h>

struct StudentAttendance
{
    int matric_num;
    char student_name[50];
    bool absent_present;
};

int main()
{
    struct StudentAttendance studentAttendance[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Student: %d\n", i + 1);
        printf("Enter Student name: \n");
        scanf("%[^\n]", studentAttendance[i].student_name);
    }
}