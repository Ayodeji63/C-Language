#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DRUGS 100

struct Drug
{
    char drugName[50];
    char manufacturer[50];
    char dateOfStock[20];
    char expiryDate[20];
};

struct DrugDatabase
{
    struct Drug drugs[MAX_DRUGS];
    int count;
};

void registerDrug(struct DrugDatabase *database);
void queryDrug(struct DrugDatabase *database, char *drugName);
void flagExpiringDrugs(struct DrugDatabase *database);
int main()
{
    struct DrugDatabase database;
    database.count = 0;

    int choice;
    do
    {
        printf("========== A & J Pharmaceutical Industry ==========\n");
        printf("1. Register a drug\n");
        printf("2. Query drug information\n");
        printf("3. Flag expiring drugs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerDrug(&database);
            break;
        case 2:
        {
            char drugName[50];
            printf("Enter the name of the drug: ");
            scanf("%s", drugName);
            queryDrug(&database, drugName);
            break;
        }
        case 3:
            flagExpiringDrugs(&database);
            break;
        case 4:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please try again \n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}

void registerDrug(struct DrugDatabase *database)
{
    struct Drug newDrug;

    printf("Enter drug name: ");
    scanf("%s", newDrug.drugName);

    printf("Enter drug manufacturer: ");
    scanf("%s", newDrug.manufacturer);

    printf("Enter date of stock (dd/mm/yyyy): ");
    scanf("%s", newDrug.dateOfStock);

    printf("Enter expiry date (dd/mm/yyyy): ");
    scanf("%s", newDrug.expiryDate);

    database->drugs[database->count] = newDrug;
    database->count++;

    printf("Drug registered successfully!\n");
}

void queryDrug(struct DrugDatabase *database, char *drugName)
{
    bool drugFound = false;

    for (int i = 0; i < database->count; i++)
    {
        if (strcmp(database->drugs[i].drugName, drugName) == 0)
        {
            printf("\nDrug Name: %s\n", database->drugs[i].drugName);
            printf("Manufacturer: %s\n", database->drugs[i].manufacturer);
            printf("Date of Stock: %s\n", database->drugs[i].dateOfStock);
            printf("Expiry Date: %s\n", database->drugs[i].expiryDate);
            drugFound = true;
            break;
        }
    }

    if (!drugFound)
    {
        printf("Drug not found in the database.\n");
    }
}

void flagExpiringDrugs(struct DrugDatabase *database)
{
    printf("\nExpiring Drugs: \n");
    for (int i = 0; i < database->count; i++)
    {
        // Assume the expiry data format is
        int currentYear, currentMonth, currentDay;
        sscanf(database->drugs[i].expiryDate, "%d/%d/%d", &currentDay, &currentMonth, &currentYear);
        // printf("%d, %d, %d", currentDay, currentMonth, currentYear);
        // Get the current date
        // You may need to adjust this part based on your system or use a library to get the current date
        int year = 2023;
        int month = 5;
        int day = 14;

        if (currentYear == year && currentMonth == month && currentDay - day <= 30)
        {
            printf("Drug Name: %s\n", database->drugs[i].drugName);
            printf("Manufacturer: %s\n", database->drugs[i].manufacturer);
            printf("Expiry Date: %s\n", database->drugs[i].expiryDate);
            printf("---------------------\n");
        }
    }
}