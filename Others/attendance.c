#include <stdio.h>
#include <stdbool.h>

struct attendance
{
    int matric_num;
    char student_name[50];
    bool absent_present;
};

int main()
{
    struct attendance Attedances[2];

    int i;

    printf("Enter Attendance \n");

    for (i = 0; i < 2; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Enter Matric Number: \n");
        scanf("%d", &Attedances[i].matric_num);
        printf("Enter name: \n");
        scanf("%s", Attedances[i].student_name);
        printf("Enter Present/Absent: \n");
        scanf("%d", Attedances[i].absent_present);
    }

    printf("Attendance of %d Students:\n", 2);

    for (i = 0; i < 2; i++)
    {
        printf("Matric Number: %d\n", Attedances[i].matric_num);
        printf("Student Name: %s\n", Attedances[i].student_name);
        printf("Present/Absent: %d\n", Attedances[i].absent_present);
    }

    return 0;
}
