#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// GROUP 2 and 10
// A & J Pharmaceutical Industry has requested that your group should do a software to help her routine operations which include :
// (i)Registering into a database all drugs stocked at any given time.
// (ii)Querying and obtaining information per time on any particular kind of drug with drugname, manufacturer, date_of_stock, expiry_date.
// (iii)Flaging details of any drug(giving advance notice) billed to expiry in a month time.

#define MAX_DRUGS 100

// Drug Infos
struct Drug
{
    char drugName[50];
    char manufacturer[50];
    char dateOfStock[20];
    char expiryDate[20];
};

// Drug Database
struct DrugDatabase
{
    // Array of structures
    struct Drug drugs[MAX_DRUGS];
    // drug count
    int count;
};

// Functions Declarations
void registerDrug(struct DrugDatabase *database);
void queryDrug(struct DrugDatabase *database, char *drugName);
void flagExpiringDrugs(struct DrugDatabase *database);

int main()
{
    // data-type        // variable
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

// Functions Initialization
void registerDrug(struct DrugDatabase *database)
{
    struct Drug newDrug;

    printf("Enter drug name: ");
    scanf(" %[^\n]", newDrug.drugName);

    printf("Enter drug manufacturer: ");
    scanf(" %[^\n]", newDrug.manufacturer);

    printf("Enter date of stock (dd/mm/yyyy): ");
    scanf(" %[^\n]", newDrug.dateOfStock);

    printf("Enter expiry date (dd/mm/yyyy): ");
    scanf(" %[^\n]", newDrug.expiryDate);

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
        // 10 / 02 / 2023

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