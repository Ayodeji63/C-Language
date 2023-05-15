#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX_MEMBERS 3

struct Member
{
    char name[50];
    char address[100];
    int age;
    int loanDuration;
    char occupation[50];
    char membershipDate[20];
    float deposits;
    float loan;
};

struct CooperativeSociety
{
    struct Member members[3];
    int count;
};

void addMember(struct CooperativeSociety *society);

void recordAssetsAndLiabilities(struct CooperativeSociety *society);

void printAllMember(struct CooperativeSociety *society);
void provideLoan(struct CooperativeSociety *society);
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
        printf("5. Print All Members\n");
        printf("6. Exit\n");
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
        case 5:
            printAllMember(&society);
            break;
        default:
            break;
        }
    } while (choice != 6);
}

void addMember(struct CooperativeSociety *society)
{
    if (society->count >= 3)
    {
        printf("Maximum member limit reached \n");
        return;
    }
    society->count++;
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

    society->members[society->count - 1] = newMember;

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

void provideLoan(struct CooperativeSociety *society)
{
    char memberName[50];
    printf("Enter Member Name: ");
    scanf(" %[^\n]", memberName);

    bool found = false;

    for (int i = 0; i < society->count; i++)
    {
        if (strcmp(memberName, society->members[i].name) == 0)
        {

            // Calculate the membership duration in months
            time_t now = time(NULL);

            struct tm *currentTime = localtime(&now);

            int currentMonth = currentTime->tm_mon + 1;    // Month starts from 0
            int currentYear = currentTime->tm_year + 1900; // Years since 1900

            int membershipDuration = ((currentYear - atoi(society->members[i].membershipDate + 6)) * 12) + (currentMonth - atoi(society->members[i].membershipDate + 3));

            printf("\n%s has been member for %d months \n", memberName, membershipDuration);

            if (membershipDuration >= 6)
            {
                // loan duration
                printf("\n \nInput Loan Duration: \n");
                scanf("%d", &(society->members[i].loanDuration));
                printf("Loan duration is %d months\n", society->members[i].loanDuration);

                // Calculate interest Rate
                float interestRate = 0.0;
                if (society->members[i].loanDuration <= 12)
                {
                    interestRate = 5.0;
                }
                // else if (society->members[i].loanDuration == 18)
                // {
                //     interestRate = 8.0;
                // }

                // Calculate interest Amount
                float interestAmount = (interestRate / 100) * society->members[i].loan;
                printf("Interest Amount is %f \n", interestAmount);

                // Calculate the loan amount
                float loanAmount = 2 * society->members[i].deposits + interestAmount;
                society->members[i].loan += loanAmount;

                printf("Loan granted: %.2f\n", loanAmount);
            }
            else
            {
                printf("Member is not eligible for a loan.\n");
            }

            found = true;

            break;
        }
    }

    if (!found)
    {
        printf("Member not found!\n");
    }
}

void printAllMember(struct CooperativeSociety *society)
{
    for (int i = 0; i < MAX_MEMBERS; i++)
    {
        printf("\nMember : %d \n", i + 1);
        printf("Name: %s", society->members[i].name);
        printf("\nAddress: %s", society->members[i].address);
        printf("\nOccupation: %s", society->members[i].occupation);
        printf("\nAge: %d", society->members[i].age);
        printf("\nDeposits: %f\n", society->members[i].deposits);
        printf("\nLoans: %f", society->members[i].loan);
        }
}