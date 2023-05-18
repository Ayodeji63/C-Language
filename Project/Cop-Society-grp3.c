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
void deductLoan(struct CooperativeSociety *society);
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
        printf("4. Deduct Loan\n");
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
        case 4:
            deductLoan(&society);
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
                int loanDuration;
                printf("\n \nInput Loan Duration: \n");
                scanf("%d", &loanDuration);
                society->members[i].loanDuration = loanDuration;
                printf("Loan duration is %d months\n", society->members[i].loanDuration);

                // Calculate interest Rate
                float interestRate = 0.0;
                if (loanDuration < 13)
                {
                    interestRate = 5.0;
                }
                else if (loanDuration >= 18)
                {
                    interestRate = 8.0;
                }
                printf("Interest rate is %.2f \n", interestRate);
                // Calculate the loan amount
                float loanAmount = 2 * society->members[i].deposits;
                printf("Loan granted: %.2f\n", loanAmount);
                // Calculate interest Amount
                float interestAmount = (interestRate / 100) * loanAmount;
                printf("Interest Amount is %.2f \n", interestAmount);
                float totalAmount = loanAmount + interestAmount;
                society->members[i].loan += totalAmount;
                printf("Total loan amount plus interest is %f \n", totalAmount);
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

void deductLoan(struct CooperativeSociety *society)
{
    for (int i = 0; i < society->count; i++)
    {
        // Deduct the monthly loan installment from deposits
        float monthlyInstallment = society->members[i].loan / society->members[i].loanDuration;
        society->members[i].deposits -= monthlyInstallment;
    }
}

void printAllMember(struct CooperativeSociety *society)
{
    for (int i = 0; i < society->count; i++)
    {
        printf("\nMember : %d \n", i + 1);
        printf("Name: %s", society->members[i].name);
        printf("\nAddress: %s", society->members[i].address);
        printf("\nOccupation: %s", society->members[i].occupation);
        printf("\nAge: %d", society->members[i].age);
        printf("\nDeposits: %f", society->members[i].deposits);
        printf("\nLoans: %f \n", society->members[i].loan);
    }
}