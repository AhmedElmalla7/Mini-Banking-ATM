#include <stdio.h>
#include "sharedFunctions.h"

void atmMenu(Account *account)
{
    int choice;
    void (*operation)(Account *);

    do
    {
        clearScreen();

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

        if (scanf("%d", &choice) != 1)
        {
            choice = 0; 
        }

        s32 characterDelete;
        while ((characterDelete = getchar()) != '\n' && characterDelete != EOF);

        switch (choice)
        {
        case 1:
            clearScreen();
            showBalance(account);
            printf("\nPress any key to continue...");
            _getch();
            break;

        case 2:
            clearScreen();
            operation = deposit;
            operation(account);
            printf("\nPress any key to continue...");
            _getch();
            break;

        case 3:
            clearScreen();
            operation = withdraw;
            operation(account);
            printf("\nPress any key to continue...");
            _getch();
            break;

        case 4:
            clearScreen();
            showSummary(account);
            printf("\nPress any key to continue...");
            _getch();
            break;

        case 5:
            clearScreen();

            showSummary(account);

            printf("\n\033[1;32mYou have been logged out successfully.\033[0m\n");
            printf("Thank you for using our ATM system.\n");

            printf("\n\033[1;33mPress any key to return to Main Menu...\033[0m");
            _getch();
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);
}