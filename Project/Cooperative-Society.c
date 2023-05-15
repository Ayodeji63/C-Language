#include <stdio.h>
#include <string.h>

#define MAX_MEMBERS 100

struct Member
{
    char name[50];
    char address[100];
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
void provideLoan(struct CooperativeSociety *society);
void chargeInterest(struct CooperativeSociety *society);

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
        case 3:
            provideLoan(&society);
            break;
        case 4:
            chargeInterest(&society);
            break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}

void addMember(struct CooperativeSociety *society)
{
    if (society->count >= MAX_MEMBERS)
    {
        printf("Maximum member limit reached!\n");
        return;
    }

    struct Member newMember;
    printf("Enter member name: ");
    scanf(" %[^\n]", newMember.name);
    printf("Enter member address: ");
    scanf(" %[^\n]", newMember.address);

    society->members[society->count] = newMember;
    society->count++;

    printf("Member added successfully!\n");
}

void recordAssetsAndLiabilities(struct CooperativeSociety *society)
{
    char memberName[50];
    printf("Enter member name: ");
    scanf(" %[^\n]", memberName);

    int found = 0;
    for (int i = 0; i < society->count; i++)
    {
        if (strcmp(memberName, society->members[i].name) == 0)
        {
            printf("Enter deposits: ");
            scanf("%f", &(society->members[i].deposits));
            printf("Enter loan: ");
            scanf("%f", &(society->members[i].loan));
            found = 1;
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

void provideLoan(struct CooperativeSociety *society)
{
    char memberName[50];
    printf("Enter member name: ");
    scanf(" %[^\n]", memberName);

    int found = 0;
    for (int i = 0; i < society->count; i++)
    {
        if (strcmp(memberName, society->members[i].name) == 0)
        {
            if (society->members[i].deposits >= (society->members[i].loan * 0.5))
            {
                printf("Loan approved for member %s\n", society->members[i].name);
                society->members[i].deposits -= society->members[i].loan * 0.5;
            }
            else
            {
                printf("Insufficient deposits for member %s\n", society->members[i].name
