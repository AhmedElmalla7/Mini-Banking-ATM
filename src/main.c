#include "sharedFunctions.h"

extern u32 activeCount;

void clearScreen(void)
{
    system("cls");
}

int main(void)
{
    // intialize accounts
    Account accounts[ACCOUNT_COUNT] = {
        {"1234", "1001", "Sara Ahmed", SAVINGS, 5000.0f, 0, 0},
        {"5678", "1002", "Omar Ali", CURRENT, 3500.0f, 0, 0},
        {"4321", "1003", "Mona Adel", SAVINGS, 7200.0f, 0, 0}};

    // a pointer array that refers to accounts
    Account *accountPointers[ACCOUNT_COUNT];

    for (int i = 0; i < ACCOUNT_COUNT; i++)
    {
        accountPointers[i] = &accounts[i];
    }
    while (1)
    {
        clearScreen();

        u32 mainOp = 0;
        printf("\n\033[1;34m========================================\033[0m\n");
        printf("\033[1;36m       MINI BANKING & ATM SYSTEM        \033[0m\n");
        printf("\033[1;34m========================================\033[0m\n");

        printf("\n  \033[1;36m[1]\033[0m \033[1;32mSign In\033[0m\n");
        printf("  \033[1;36m[2]\033[0m \033[1;36mSign Up\033[0m\n");
        printf("  \033[1;31m[3]\033[0m \033[1;31mExit\033[0m\n");
        printf("\n\033[1;33mEnter your choice :\033[0m ");

        if (scanf("%u", &mainOp) != 1)
        {
            mainOp = 0; 
        }

        int characterDelete;
        while ((characterDelete = getchar()) != '\n' && characterDelete != EOF);

        MainOperation choice = (MainOperation)mainOp;
        switch (choice)
        {
        case SIGNIN:
        {
            Account *userToLog = login(accountPointers, activeCount);

            if (userToLog != NULL)
            {
                atmMenu(userToLog);
            }
            else
            {

                printf("\n========================================\n");
                printf("       LOGIN SESSION ENDED              \n");
                printf("========================================\n");

                printf("\nPress any key to continue...");
                _getch();
            }

            break;
        }

        case SIGNUP:
            signUp(accountPointers, &activeCount, accounts);
            break;

        case EXIT:
            clearScreen();

            printf("\n\033[1;34m========================================\033[0m\n");
            printf("\033[1;36m             GOODBYE!                   \033[0m\n");
            printf("\033[1;34m========================================\033[0m\n");

            printf("\nThank you for using our ATM system.\n");
            printf("Have a great day!\n");

            printf("\n\033[1;33mPress any key to exit...\033[0m");
            _getch();

            return 0;

        default:
            printf("\n\033[1;31mInvalid choice.\033[0m\n");
            printf("Please select a valid option.\n");

            printf("\nPress any key to continue...");
            _getch();
            break;
        }
    }
    return 0;
}