#include "bank.h"
#include <stdio.h>


void atmMenu(Account *account)
{
    int choice;
    void (*operation)(Account *);

    do
    {
        printf("\n========================================\n");
        printf("       MINI BANKING & ATM SYSTEM\n");
        printf("========================================\n");
        printf("Account number: %s\n", account->accountNumber);
        printf("Welcome, %s!\n", account->name);

        printf("\n1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Session Summary\n");
        printf("5. Logout\n");

        printf("Choose: ");
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