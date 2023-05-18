#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define MAX_CUSTOMERS 100

struct Customer
{
    long accountNumber;
    char name[50];
    char accountType[20];
    float balance;
    float loan;
    char daysSinceDeposit[30];
    int passcode;
};

struct Customer lautechBank[MAX_CUSTOMERS];
int customerCount = 0;

// Dedclarations of functions
void openAccount();
void makeDeposit();
void makeWithdrawal();
void acctInfo();
void provideLoan();

long generateAccountNumber()
{
    srand(time(NULL)); // Initialize random number generator with current time

    long accountNumber = 0;
    for (int i = 0; i < 10; i++)
    {
        accountNumber = (accountNumber * 10) + (rand() % 10);
    }

    return accountNumber;
}

int main()
{
    int choice;
    do
    {
        printf("\n========== LautechBank ==========\n");
        printf("1. Open Account\n");
        printf("2. Make Deposit\n");
        printf("3. Make Withdrawal\n");
        printf("4. Request Loan \n");
        printf("5. View Account Info\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            openAccount();
            break;
        case 2:
            makeDeposit();
            break;
        case 3:
            makeWithdrawal();
            break;
        case 4:
            provideLoan();
            break;
        case 5:
            acctInfo();
            break;
        default:
            break;
        }
    } while (choice != 6);

    return 0;
}

void openAccount()
{
    if (customerCount >= MAX_CUSTOMERS)
    {
        printf("Maximum customer limit reached\n");
        return;
    }

    struct Customer newCustomer;

    printf("Enter customer name: ");
    scanf(" %[^\n]", newCustomer.name);
    printf("Enter account type (current, savings, fixed deposit): ");
    scanf(" %[^\n]", newCustomer.accountType);
    printf("Enter initial balance: ");
    scanf("%f", &newCustomer.balance);
    printf("Enter Today Date (dd/mm/yy): ");
    scanf(" %[^\n]", newCustomer.daysSinceDeposit);
    long accountNumber = generateAccountNumber();
    printf("Your account number is %ld\n", accountNumber);
    newCustomer.accountNumber = accountNumber;
    printf("Create a Passcode: ");
    scanf("%d", &newCustomer.passcode);
    lautechBank[customerCount] = newCustomer;
    customerCount++;

    printf("Account opened successfully!\n");
}

void makeDeposit()
{
    long accountNumber;
    float amount;
    int passcode;
    printf("Enter account number: ");
    scanf("%ld", &accountNumber);
    printf("Enter passcode: ");
    scanf("%d", &passcode);

    for (int i = 0; i < customerCount; i++)
    {
        if (lautechBank[i].accountNumber == accountNumber && lautechBank[i].passcode == passcode)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            lautechBank[i].balance += amount;

            // Calculate the days of Deposit duration in months
            time_t now = time(NULL);

            struct tm *currentTime = localtime(&now);

            int currentMonth = currentTime->tm_mon + 1;    // Month starts from 0
            int currentYear = currentTime->tm_year + 1900; // Years since 1900

            int depositDuration = ((currentYear - atoi(lautechBank[i].daysSinceDeposit + 6)) * 12) + (currentMonth - atoi(lautechBank[i].daysSinceDeposit + 3));

            if (depositDuration > 1)
            {
                float newAmount = (4 / 100) * lautechBank[i].balance;
                lautechBank[i].balance = newAmount;
            }

            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void makeWithdrawal()
{
    int passcode;
    long accNum;
    float amount;
    bool found = false;

    printf("Enter Account Number: ");
    scanf("%ld", &accNum);
    printf("Enter Passcode: ");
    scanf("%d", &passcode);

    for (int i = 0; i < customerCount; i++)
    {
        if (lautechBank[i].passcode == passcode && lautechBank[i].accountNumber == accNum)
        {
            printf("\n======Withdrawal In Process======\n");
            printf("Enter Amount To Withdraw: ");
            scanf("%f", &amount);
            found = true;

            if (lautechBank[i].balance >= amount)
            {
                printf("Withdrawal Successful\n");
                lautechBank[i].balance -= amount;
            }
            else
            {
                printf("Insufficient Funds\n");
            }

            return; // Exit the function after a successful withdrawal
        }
    }

    if (!found)
    {
        printf("Customer Not Found\n");
    }
}

void acctInfo()
{
    char acctName[50];
    int passcode;
    printf("Enter Account Name: ");
    scanf(" %[^\n]", acctName);
    printf("Enter passcode: ");
    scanf("%d", &passcode);
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(lautechBank[i].name, acctName) == 0 && lautechBank[i].passcode == passcode)
        {
            printf("\n======Account Details======\n");
            printf("Account Name is: %s \n", lautechBank[i].name);
            printf("Account Number is %ld\n", lautechBank[i].accountNumber);
            printf("Account Type is %s\n", lautechBank[i].accountType);
            printf("Account Balance is %.2f\n", lautechBank[i].balance);
            printf("Account Loan is: %.2f\n", lautechBank[i].loan);
            printf("Account Passcode is %d\n", lautechBank[i].passcode);
        }
    }
}

void provideLoan()
{
    long accountNumber;
    printf("Enter Account Number: ");
    scanf("%ld", &accountNumber);

    bool found = false;

    for (int i = 0; i < customerCount; i++)
    {
        if (lautechBank[i].accountNumber == accountNumber && lautechBank[i].loan == 0)
        {

            // Calculate the customer duration in months
            time_t now = time(NULL);

            struct tm *currentTime = localtime(&now);

            int currentMonth = currentTime->tm_mon + 1;    // Month starts from 0
            int currentYear = currentTime->tm_year + 1900; // Years since 1900

            int depositDuration = ((currentYear - atoi(lautechBank[i].daysSinceDeposit + 6)) * 12) + (currentMonth - atoi(lautechBank[i].daysSinceDeposit + 3));

            if (depositDuration >= 6)
            {
                // loan duration
                int loanDuration;
                printf("\n \nInput Loan Duration: \n");
                scanf("%d", &loanDuration);
                printf("Loan duration is %d months\n", loanDuration);

                // Calculate interest Rate
                float interestRate = 0.0;
                if (loanDuration < 13)
                {
                    interestRate = 2.0;
                }
                else if (loanDuration >= 18)
                {
                    interestRate = 5.0;
                }
                printf("Interest rate is %.2f \n", interestRate);
                // Calculate the loan amount
                float loanAmount = 2 * lautechBank[i].balance;
                printf("Loan granted: %.2f\n", loanAmount);
                // Calculate interest Amount
                float interestAmount = (interestRate / 100) * loanAmount;
                printf("Interest Amount is %.2f \n", interestAmount);
                float totalAmount = loanAmount + interestAmount;
                lautechBank[i].loan += totalAmount;
                printf("Total loan amount plus interest is %f \n", totalAmount);
            }
            else
            {
                printf("Customer is not eligible for a loan.\n");
            }

            found = true;

            break;
        }
    }

    if (!found)
    {
        printf("Customer not found!\n");
    }
}
