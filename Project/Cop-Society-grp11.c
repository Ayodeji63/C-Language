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
    struct Member members[MAX_MEMBERS];
    int count;
};

void displayMenu();
void executeChoice(int choice, struct CooperativeSociety *society);
void registerMember(struct CooperativeSociety *society);
void updateAssetsAndLiabilities(struct CooperativeSociety *society);
void grantLoan(struct CooperativeSociety *society);
void repayLoan(struct CooperativeSociety *society);
void viewAllMembers(struct CooperativeSociety *society);

int main()
{
    struct CooperativeSociety society;
    society.count = 0;

    int choice;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        executeChoice(choice, &society);
    } while (choice != 6);

    return 0;
}

void displayMenu()
{
    printf("========== Cooperative Society Management ==========\n");
    printf("1. Register Member\n");
    printf("2. Update Assets and Liabilities\n");
    printf("3. Grant Loan\n");
    printf("4. Repay Loan\n");
    printf("5. View All Members\n");
    printf("6. Exit\n");
}

void executeChoice(int choice, struct CooperativeSociety *society)
{
    switch (choice)
    {
    case 1:
        registerMember(society);
        break;
    case 2:
        updateAssetsAndLiabilities(society);
        break;
    case 3:
        grantLoan(society);
        break;
    case 4:
        repayLoan(society);
        break;
    case 5:
        viewAllMembers(society);
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}

void registerMember(struct CooperativeSociety *society)
{
    if (society->count >= MAX_MEMBERS)
    {
        printf("Maximum member limit reached.\n");
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

    printf("Member added successfully.\n");
}

void updateAssetsAndLiabilities(struct CooperativeSociety *society)
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

void grantLoan(struct CooperativeSociety *society)
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

            printf("\n%s has been a member for %d months.\n", memberName, membershipDuration);

            if (membershipDuration >= 6)
            {
                int loanDuration;
                printf("\nEnter Loan Duration: ");
                scanf("%d", &loanDuration);
                society->members[i].loanDuration = loanDuration;
                printf("Loan duration is %d months.\n", society->members[i].loanDuration);

                float interestRate = 0.0;
                if (loanDuration < 13)
                {
                    interestRate = 5.0;
                }
                else if (loanDuration >= 18)
                {
                    interestRate = 8.0;
                }
                printf("Interest rate is %.2f.\n", interestRate);

                float loanAmount = 2 * society->members[i].deposits;
                printf("Loan granted: %.2f.\n", loanAmount);

                float interestAmount = (interestRate / 100) * loanAmount;
                printf("Interest Amount is %.2f.\n", interestAmount);

                float totalAmount = loanAmount + interestAmount;
                society->members[i].loan += totalAmount;
                printf("Total loan amount plus interest is %.2f.\n", totalAmount);
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

void repayLoan(struct CooperativeSociety *society)
{
    for (int i = 0; i < society->count; i++)
    {
        float monthlyInstallment = society->members[i].loan / society->members[i].loanDuration;
        society->members[i].deposits -= monthlyInstallment;
    }
}

void viewAllMembers(struct CooperativeSociety *society)
{
    for (int i = 0; i < society->count; i++)
    {
        printf("\nMember: %d\n", i + 1);
        printf("Name: %s\n", society->members[i].name);
        printf("Address: %s\n", society->members[i].address);
        printf("Occupation: %s\n", society->members[i].occupation);
        printf("Age: %d\n", society->members[i].age);
        printf("Deposits: %.2f\n", society->members[i].deposits);
        printf("Loans: %.2f\n", society->members[i].loan);
    }
}
