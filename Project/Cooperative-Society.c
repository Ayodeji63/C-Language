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
            // Calculate the membership duration in months
            time_t now = time(NULL);
            struct tm *currentTime = localtime(&now);
            int currentMonth = currentTime->tm_mon + 1;    // Month starts from 0
            int currentYear = currentTime->tm_year + 1900; // Years since 1900

            int membershipDuration = ((currentYear - atoi(society->members[i].membershipDate + 6)) * 12) + (currentMonth - atoi(society->members[i].membershipDate + 3));

            if (membershipDuration >= 6) // Check if the member is eligible for a loan
            {
                printf("Enter deposits: ");
                scanf("%f", &(society->members[i].deposits));

                // Calculate the loan amount
                float loanAmount = 2 * society->members[i].deposits;
                society->members[i].loan = loanAmount;

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
