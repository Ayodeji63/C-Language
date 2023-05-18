#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define MAX_CUSTOMERS 100

struct Customer
{
    long acctNum;
    char acctName[50];
    char accountType[20];
    float balance;
    float loan;
    char depositDate[30];
    int password;
};

struct Customer bank[MAX_CUSTOMERS];
int customerCount = 0;

void openCustomerAccount();
void makeDepositTransaction();
void makeWithdrawalTransaction();
void viewAccountInformation();
void provideLoanAssistance();

long generateacctNum()
{
    srand(time(NULL)); // Initialize random number generator with current time

    long acctNum = 0;
    for (int i = 0; i < 10; i++)
    {
        acctNum = (acctNum * 10) + (rand() % 10);
    }

    return acctNum;
}

int main()
{
    int choice;
    do
    {
        printf("\n========== Bank System ==========\n");
        printf("1. Open Customer Account\n");
        printf("2. Make Deposit Transaction\n");
        printf("3. Make Withdrawal Transaction\n");
        printf("4. Provide Loan Assistance\n");
        printf("5. View Account Information\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            openCustomerAccount();
            break;
        case 2:
            makeDepositTransaction();
            break;
        case 3:
            makeWithdrawalTransaction();
            break;
        case 4:
            provideLoanAssistance();
            break;
        case 5:
            viewAccountInformation();
            break;
        default:
            break;
        }
    } while (choice != 6);

    return 0;
}

void openCustomerAccount()
{
    if (customerCount >= MAX_CUSTOMERS)
    {
        printf("Maximum customer limit reached\n");
        return;
    }

    struct Customer newCustomer;

    printf("Enter customer name: ");
    scanf(" %[^\n]", newCustomer.acctName);
    printf("Enter account type (current, savings, fixed deposit): ");
    scanf(" %[^\n]", newCustomer.accountType);
    printf("Enter initial balance: ");
    scanf("%f", &newCustomer.balance);
    printf("Enter today's date (dd/mm/yy): ");
    scanf(" %[^\n]", newCustomer.depositDate);
    long acctNum = generateacctNum();
    printf("Your account number is %ld\n", acctNum);
    newCustomer.acctNum = acctNum;
    printf("Create a password: ");
    scanf("%d", &newCustomer.password);
    bank[customerCount] = newCustomer;
    customerCount++;

    printf("Account opened successfully!\n");
}

void makeDepositTransaction()
{
    long acctNum;
    float amount;
    int password;
    printf("Enter account number: ");
    scanf("%ld", &acctNum);
    printf("Enter password: ");
    scanf("%d", &password);

    for (int i = 0; i < customerCount; i++)
    {
        if (bank[i].acctNum == acctNum && bank[i].password == password)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            bank[i].balance += amount;

            // Calculate the deposit duration in months
            time_t now = time(NULL);
            struct tm *currentTime = localtime(&now);
            int currentMonth = currentTime->tm_mon + 1;    // Month starts from 0
            int currentYear = currentTime->tm_year + 1900; // Years since 1900

            int depositDuration = ((currentYear - atoi(bank[i].depositDate + 6)) * 12) + (currentMonth - atoi(bank[i].depositDate + 3));

            if (depositDuration > 1)
            {
                float newAmount = (4 / 100) * bank[i].balance;
                bank[i].balance = newAmount;
            }

            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void makeWithdrawalTransaction()
{
    int password;
    long acctNum;
    float amount;
    bool found = false;

    printf("Enter Account Number: ");
    scanf("%ld", &acctNum);
    printf("Enter password: ");
    scanf("%d", &password);

    for (int i = 0; i < customerCount; i++)
    {
        if (bank[i].password == password && bank[i].acctNum == acctNum)
        {
            printf("\n======Withdrawal In Process======\n");
            printf("Enter Amount To Withdraw: ");
            scanf("%f", &amount);
            found = true;

            if (bank[i].balance >= amount)
            {
                printf("Withdrawal Successful\n");
                bank[i].balance -= amount;
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

void viewAccountInformation()
{
    char accountName[50];
    int password;
    printf("Enter Account Name: ");
    scanf(" %[^\n]", accountName);
    printf("Enter password: ");
    scanf("%d", &password);
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(bank[i].acctName, accountName) == 0 && bank[i].password == password)
        {
            printf("\n======Account Details======\n");
            printf("Account Name is: %s \n", bank[i].acctName);
            printf("Account Number is %ld\n", bank[i].acctNum);
            printf("Account Type is %s\n", bank[i].accountType);
            printf("Account Balance is %.2f\n", bank[i].balance);
            printf("Account Loan is: %.2f\n", bank[i].loan);
            printf("Account password is %d\n", bank[i].password);
        }
    }
}

void provideLoanAssistance()
{
    long acctNum;
    printf("Enter Account Number: ");
    scanf("%ld", &acctNum);

    bool found = false;

    for (int i = 0; i < customerCount; i++)
    {
        if (bank[i].acctNum == acctNum)
        {
            printf("\n======Loan Assistance======\n");
            printf("Loan amount: ");
            scanf("%f", &bank[i].loan);
            found = true;
            printf("Loan provided successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Customer not found\n");
    }
}
