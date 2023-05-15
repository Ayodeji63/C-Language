#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MEMBERS 2

struct Member
{
    char name[50];
    char address[100];
    int age;
    char occupation[50];
    char membershipDate[20];
    float deposits;
    float loan;
};

struct CooperativeSociety
{
    struct Member members[MAX_MEMBERS];
    int count;
};

void addMember(struct CooperativeSociety *society);

void recordAssetsAndLiabilities(struct CooperativeSociety *society);

void printAllMember(int numMembers, struct CooperativeSociety *society);
int main()
{
    struct CooperativeSociety society;
    society.count = 0;

    int choice;

    do
    {
        printf("========== Cooperative Society Management ==========\n");
        printf("1. Add Member\n");
        printf("2. Record Assets and Liabilities\n");
        printf("3. Provide Loan\n");
        printf("4. Charge Interest\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addMember(&society);
            break;
        case 2:
            recordAssetsAndLiabilities(&society);
            break;
        default:
            printAllMember(MAX_MEMBERS, &society);
            break;
        }
    } while (choice != 5);
}

void addMember(struct CooperativeSociety *society)
{
    if (society->count >= MAX_MEMBERS)
    {
        printf("Maximum member limit reached \n");
        return;
    }

    struct Member newMember;
    printf("Enter member name: ");
    scanf(" %[^\n]", newMember.name);
    printf("Enter member address: ");
    scanf(" %[^\n]", newMember.address);
    printf("Enter member occupation: ");
    scanf(" %[^\n]", newMember.occupation);
    printf("Enter member age: ");
    scanf("%d", &newMember.age);
    printf("Enter Membership (dd/mm/yyyy): ");
    scanf("%s", newMember.membershipDate);

    society->members[society->count] = newMember;
    society->count++;

    printf("Member added successfully \n");
}

void recordAssetsAndLiabilities(struct CooperativeSociety *society)
{
    char memberName[50];
    printf("Enter Member Name: ");
    scanf(" %[^\n]", memberName);

    bool found = false;

    for (int i = 0; i < society->count; i++)
    {
        if (strcmp(memberName, society->members[i].name) == 0)
        {
            printf("Enter deposits: ");
            scanf("%f", &(society->members[i].deposits));

            printf("Enter loan: ");
            scanf("%f", &(society->members[i].loan));
            found = true;
            break;
        }
    }

    if (found)
    {
        printf("Assets and liabilities recorded successfully!\n");
    }
    else
    {
        printf("Member not found!\n");
    }
}

void printAllMember(int numMembers, struct CooperativeSociety *society)
{
    for (int i = 0; i < numMembers; i++)
    {
        printf("\nMember : %d \n", i + 1);
        printf("Name: %s", society[i].members->name);
        printf("\nAddress: %s", society[i].members->address);
        printf("\nOccupation: %s", society[i].members->occupation);
        printf("\nAge: %d", society[i].members->age);
        printf("\nLoans: %f", society[i].members->loan);
        printf("\nDeposits: %f\n", society[i].members->deposits);
    }
}