#include "bank.h"
#include <stdio.h>


void atmMenu(Account *currentAccount)
{
    int choice;

    void (*operations[])() = {
        checkBalance,
        deposit,
        withdraw,
        sessionSummary
    };

    while (1)
    {
        printf("\n========================================\n");
        printf("        MINI BANKING & ATM SYSTEM\n");
        printf("========================================\n");

        printf("Account number: %s\n", currentAccount->accountNumber);
        printf("PIN: %s\n", currentAccount->pin);
        printf("\nWelcome, %s!\n\n", currentAccount->name);

        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Session Summary\n");
        printf("5. Logout\n");

        printf("\nChoose Option's Number : ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            printf("Logged out successfully.\n");
            break;
        }

        if (choice >= 1 && choice <= 4)
        {
            operations[choice - 1]();
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }
}
