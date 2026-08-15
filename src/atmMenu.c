#include <stdio.h>
#include "sharedFunctions.h"

void atmMenu(Account *account)
{
    int choice;
    void (*operation)(Account *);

    do
    {
        // Blue borders and a Cyan title
        printf("\n\033[1;34m========================================\033[0m\n");
        printf("\033[1;36m       MINI BANKING & ATM SYSTEM        \033[0m\n");
        printf("\033[1;34m========================================\033[0m\n");

        // Standard text for the label, yellow for the account number
        printf("Account number: \033[1;33m%s\033[0m\n", account->accountNumber);

        // Bold and Green for the user's name!
        printf("Welcome, \033[1;32m%s\033[0m!\n", account->name);

        // Cyan brackets around the numbers to make them pop
        printf("\n  \033[1;36m[1]\033[0m Check Balance\n");
        printf("  \033[1;36m[2]\033[0m Deposit\n");
        printf("  \033[1;36m[3]\033[0m Withdraw\n");
        printf("  \033[1;36m[4]\033[0m Session Summary\n");

        // Red for the logout/exit option
        printf("  \033[1;31m[5]\033[0m Logout\n");

        // A nice yellow prompt for the user input
        printf("\n\033[1;33mChoose an option:\033[0m ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showBalance(account);
            break;

        case 2:
            operation = deposit;
            operation(account);
            break;

        case 3:
            operation = withdraw;
            operation(account);
            break;

        case 4:
            showSummary(account);
            break;

        case 5:
            showSummary(account);
            printf("Thank you for using our ATM.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);
}